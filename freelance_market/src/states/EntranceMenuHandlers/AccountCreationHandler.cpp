#include "AccountCreationHandler.h"
#include "UserExistHandler.h"
#include "UserInteraction.h"
#include "FreelanceMarket.h"
#include "UserManager.h"
#include <string>
#include <vector>

extern FreelanceMarket freelance_market;
extern UserManager user_manager;

//
// CLASS AccountCreationHandler STARTS
//

AccountCreationHandler::AccountCreationHandler() {}

bool AccountCreationHandler::handle(const Request& request) {
    next_handler_ = buildHandlersChain(UserExistHandler());
    if (BaseHandler::handle(request)) {
        auto user_type = request.get(UserType::USER);
        if (user_type == UserType::COMPANY || user_type == UserType::PERSON) {
            user_type = UserType::CLIENT;
        }
        std::string user_id = user_manager.addUser(request);
        freelance_market.setUser(User(user_id, user_type));
        return true;
    }
    return false;
}

// 
// CLASS AccountCreationHandler ENDS
//
