#include "FreelancerLogInHandler.h"
#include "AuthorizationHandler.h"
#include "UserInteraction.h"
#include <string>
#include <vector>

//
// CLASS FreelancerLogInHandler STARTS
//

FreelancerLogInHandler::FreelancerLogInHandler() {}

bool FreelancerLogInHandler::handle(const Request& request) {
    if (request.getType() == RequestType::FREELANCER_LOG_IN) {
        std::vector<std::string> requested_data = {
            "Email", 
            "Password"
        };
        Request new_request = UserInteraction::getUserData(requested_data);
        new_request.setType(RequestType::ENTER_ACCOUNT);
        new_request.set(UserType::USER, UserType::FREELANCER);
        return buildHandlersChain(AuthorizationHandler())->handle(new_request);
    } else {
        return BaseHandler::handle(request);
    }
}

// 
// CLASS FreelancerLogInHandler ENDS
//