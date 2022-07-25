#include "LogInHandler.h"
#include "FreelancerLogInHandler.h"
#include "ClientLogInHandler.h"
#include "SignUpHandler.h"
#include "UserInteraction.h"
#include <string>
#include <vector>
#include <iostream>

//
// CLASS LogInHandler STARTS
//

LogInHandler::LogInHandler() {}

bool LogInHandler::handle(const Request& request) {
    if (request.getType() == RequestType::LOG_IN) {
        std::vector<std::string> options = {
            RequestType::CLIENT_LOG_IN,
            RequestType::FREELANCER_LOG_IN,
            RequestType::SIGN_UP
        };
        Request new_request = UserInteraction::processOptions(options, [](std::string option) {
            std::cout << option << std::endl;
        });
        return buildHandlersChain(FreelancerLogInHandler(), ClientLogInHandler(), SignUpHandler())->handle(new_request);
    } else {
        return BaseHandler::handle(request);
    }
}

// 
// CLASS LogInHandler ENDS
//
