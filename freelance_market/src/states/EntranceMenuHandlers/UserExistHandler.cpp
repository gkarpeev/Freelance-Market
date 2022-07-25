#include "UserExistHandler.h"
#include "UserManager.h"
#include "User.h"
#include <iostream>

//
// CLASS UserExistHandler STARTS
//

extern UserManager user_manager;

UserExistHandler::UserExistHandler() {}

bool UserExistHandler::handle(const Request& request) {
    if (request.getType() == RequestType::CREATE_ACCOUNT) {
        std::cout << "User NOT Exist checking..." << std::endl;
        if (user_manager.checkIfUserExist(request)) {
            std::cout << "User already exists!" << std::endl;
            return false;
        }
        if (next_handler_) return BaseHandler::handle(request);
        else return true;
    } else if (request.getType() == RequestType::ENTER_ACCOUNT) {
        std::cout << "User Exist checking..." << std::endl;
        if (!user_manager.checkIfUserExist(request)) {
            std::cout << "User does not exist!" << std::endl;
            return false;
        }
        std::string user_id = user_manager.getUserID(request);
        std::string user_type = user_manager.getUserData(user_id).get(UserType::USER);
        if (user_type == "Company" || user_type == "Person") {
            user_type = UserType::CLIENT;
        }
        if (request.get(UserType::USER) != user_type) {
            std::cout << "Wrong USER type!" << std::endl;
            return false;
        }
        if (next_handler_) return BaseHandler::handle(request);
        else return true;
    } else  {
        return BaseHandler::handle(request);
    }
}


//
// CLASS UserExistHandler ENDS
//