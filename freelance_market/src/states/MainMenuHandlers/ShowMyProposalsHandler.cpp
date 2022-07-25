#include "ShowMyProposalsHandler.h"
#include "UserInteraction.h"
#include "FreelanceMarket.h"
#include <iostream>

extern FreelanceMarket freelance_market;

ShowMyProposalsHandler::ShowMyProposalsHandler() {}

bool ShowMyProposalsHandler::handle(const Request& request) {
    if (request.getType() == RequestType::SHOW_MY_PROPOSALS) {
        // std::cerr << "[DEBUG] " << "ShowMyProposalsHandler" << std::endl;
        
        std::string freelancer_id = freelance_market.getUser().getUserId();
        UserInteraction::printFreelancerProposals(freelancer_id);
        
        std::vector<std::string> options = {
            RequestType::MENU
        };
        Request new_request = UserInteraction::processOptions(options, [](std::string option) {
            std::cout << option << std::endl;
        });
        if (next_handler_) return BaseHandler::handle(request);
        else return true;
    } else {
        return BaseHandler::handle(request);
    }
}