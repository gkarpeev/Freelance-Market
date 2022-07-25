#include "ShowProposalsHandler.h"
#include "AcceptProposalHandler.h"
#include "DeclineProposalHandler.h"
#include "UserInteraction.h"
#include "FreelanceMarket.h"
#include <iostream>

extern FreelanceMarket freelance_market;

ShowProposalsHandler::ShowProposalsHandler() {}

bool ShowProposalsHandler::handle(const Request& request) {
    if (request.getType() == RequestType::SHOW_PROPOSALS_TO_MY_ORDERS) {
        // std::cerr << "[DEBUG] " << "ShowProposalsHandler" << std::endl;

        std::string client_id = freelance_market.getUser().getUserId();
        UserInteraction::printProposalsToClient(client_id);

        std::vector<std::string> options = {
            RequestType::ACCEPT_PROPOSAL,
            RequestType::DECLINE_PROPOSAL,
            RequestType::MENU
        };
        Request new_request = UserInteraction::processOptions(options, [](std::string option) {
            std::cout << option << std::endl;
        });
        return buildHandlersChain(AcceptProposalHandler(), DeclineProposalHandler())->handle(new_request);
    } else {
        return BaseHandler::handle(request);
    }
}