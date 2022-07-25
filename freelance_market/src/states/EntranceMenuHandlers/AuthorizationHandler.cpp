#include "AuthorizationHandler.h"
#include "UserExistHandler.h"
#include "ValidPasswordHandler.h"
#include "User.h"
#include "FreelanceMarket.h"
#include "UserManager.h"

extern FreelanceMarket freelance_market;
extern UserManager user_manager;

//
// CLASS AuthorizationHandler STARTS
//

AuthorizationHandler::AuthorizationHandler() {}

bool AuthorizationHandler::handle(const Request& request) {
    next_handler_ = buildHandlersChain(UserExistHandler(), ValidPasswordHandler());
    if (BaseHandler::handle(request)) {
        std::string user_id = user_manager.getUserID(request);
        auto user_type = request.get(UserType::USER);
        freelance_market.setUser(User(user_id, user_type));
        return true;
    }
    return false;
}

// 
// CLASS AccountCreationHandler ENDS
//
