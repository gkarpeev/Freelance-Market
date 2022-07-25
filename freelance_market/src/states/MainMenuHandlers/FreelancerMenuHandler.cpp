#include "FreelancerMenuHandler.h"
#include "ShowMyProposalsHandler.h"
#include "ShowTakenOrdersHandler.h"
#include "ShowAvailableOrdersHandler.h"
#include "LogOutHandler.h"
#include "UserInteraction.h"
#include <iostream>

FreelancerMenuHandler::FreelancerMenuHandler() {}

bool FreelancerMenuHandler::handle(const Request& request) {
    if (request.getType() == RequestType::MENU && request.get(UserType::USER) == UserType::FREELANCER) {
        // std::cerr << "[DEBUG] " << "FreelancerMenuHandler" << std::endl;
        std::vector<std::string> options = {
            RequestType::SHOW_MY_PROPOSALS,
            RequestType::SHOW_TAKEN_ORDERS,
            RequestType::SHOW_AVAILABLE_ORDERS,
            RequestType::LOG_OUT
        };
        Request new_request = UserInteraction::processOptions(options, [](std::string option) {
            std::cout << option << std::endl;
        });
        return buildHandlersChain(ShowMyProposalsHandler(), ShowTakenOrdersHandler(), 
                                  ShowAvailableOrdersHandler(), LogOutHandler())->handle(new_request);
    } else {
        return BaseHandler::handle(request);
    }
}