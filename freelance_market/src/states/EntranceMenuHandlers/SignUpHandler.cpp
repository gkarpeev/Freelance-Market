#include "SignUpHandler.h"
#include "FreelancerSignUpHandler.h"
#include "ClientSignUpHandler.h"
#include "UserInteraction.h"
#include <string>
#include <vector>
#include <iostream>

// 
// CLASS SignUpHandler STARTS
//

SignUpHandler::SignUpHandler() {
}

bool SignUpHandler::handle(const Request& request) {
    if (request.getType() == RequestType::SIGN_UP) {
        std::vector<std::string> options = {
            RequestType::CLIENT_SIGN_UP,
            RequestType::FREELANCER_SIGN_UP,
            RequestType::LOG_IN
        };
        Request new_request = UserInteraction::processOptions(options, [](std::string option) {
            std::cout << option << std::endl;
        });
        return buildHandlersChain(FreelancerSignUpHandler(), ClientSignUpHandler())->handle(new_request);
    } else {
        return BaseHandler::handle(request);
    }
}

//
// CLASS SignUpHandler ENDS
//