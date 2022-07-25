#include "PersonSignUpHandler.h"
#include "AccountCreationHandler.h"
#include "UserInteraction.h"
#include <string>
#include <vector>

// 
// CLASS PersonSignUpHandler STARTS
//

PersonSignUpHandler::PersonSignUpHandler() {}

bool PersonSignUpHandler::handle(const Request& request) {
    if (request.getType() == RequestType::PERSON_SIGN_UP) {
        std::vector<std::string> requested_data = {
            "First Name", 
            "Last Name", 
            "Email", 
            "Password", 
            "Country"  
        };
        Request new_request = UserInteraction::getUserData(requested_data);
        new_request.setType(RequestType::CREATE_ACCOUNT);
        new_request.set(UserType::USER, UserType::PERSON);
        return buildHandlersChain(AccountCreationHandler())->handle(new_request);
    } else {
        return BaseHandler::handle(request);
    }
}

//
// CLASS PersonSignUpHandler ENDS
//