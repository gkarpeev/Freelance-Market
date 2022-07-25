#include "ValidPasswordHandler.h"
#include "UserManager.h"
#include <iostream>

// 
// CLASS ValidPasswordHandler STARTS
//

extern UserManager user_manager;

ValidPasswordHandler::ValidPasswordHandler() {}

bool ValidPasswordHandler::handle(const Request& request) {
    if (request.getType() == RequestType::ENTER_ACCOUNT) {
        std::cout << "Valid password checking..." << std::endl;
        if (!user_manager.checkValidPassword(request)) {
            std::cout << "Wrong password!" << std::endl;
            return false;
        }
        if (next_handler_) return BaseHandler::handle(request);
        else return true;
    } else {
        return BaseHandler::handle(request);
    }
}

//
// CLASS ValidPasswordHandler ENDS
//
