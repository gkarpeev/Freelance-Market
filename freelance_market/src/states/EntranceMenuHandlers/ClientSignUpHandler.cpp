#include "ClientSignUpHandler.h"
#include "CompanySignUpHandler.h"
#include "PersonSignUpHandler.h"
#include "UserInteraction.h"
#include <iostream>

// 
// CLASS ClientSignUpHandler STARTS
//

ClientSignUpHandler::ClientSignUpHandler() {}

bool ClientSignUpHandler::handle(const Request& request) {
    if (request.getType() == RequestType::CLIENT_SIGN_UP) {
        std::vector<std::string> options = {
            RequestType::COMPANY_SIGN_UP,
            RequestType::PERSON_SIGN_UP,
            RequestType::LOG_IN
        };
        Request new_request = UserInteraction::processOptions(options, [](std::string option) {
            std::cout << option << std::endl;
        });
        return buildHandlersChain(CompanySignUpHandler(), PersonSignUpHandler())->handle(new_request);
    } else {
        return BaseHandler::handle(request);
    }
}

//
// CLASS ClientSignUpHandler ENDS
//