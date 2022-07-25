#include "FreelancerSignUpHandler.h"
#include "AccountCreationHandler.h"
#include "UserInteraction.h"
#include <string>
#include <vector>

// 
// CLASS FreelancerSignUpHandler STARTS
//

FreelancerSignUpHandler::FreelancerSignUpHandler() {}

bool FreelancerSignUpHandler::handle(const Request& request) {
    if (request.getType() == RequestType::FREELANCER_SIGN_UP) {
        std::vector<std::string> requested_data = {
            "First Name", 
            "Last Name", 
            "Email", 
            "Password", 
            "Country"  
        };
        Request new_request = UserInteraction::getUserData(requested_data);
        new_request.setType(RequestType::CREATE_ACCOUNT);
        new_request.set(UserType::USER, UserType::FREELANCER);
        return buildHandlersChain(AccountCreationHandler())->handle(new_request);
    } else {
        return BaseHandler::handle(request);
    }
}

//
// CLASS FreelancerSignUpHandler ENDS
//