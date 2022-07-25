#include "AcceptProposalHandler.h"
#include "OrdersManager.h"
#include "FreelanceMarket.h"
#include "UserInteraction.h"
#include <iostream>

extern FreelanceMarket freelance_market;
extern OrdersManager orders_manager;

AcceptProposalHandler::AcceptProposalHandler() {}

bool AcceptProposalHandler::handle(const Request& request) {
    if (request.getType() == RequestType::ACCEPT_PROPOSAL) {
        // std::cerr << "[DEBUG] " << "AcceptProposalHandler" << std::endl;
        std::string client_id = freelance_market.getUser().getUserId();
        auto proposals = orders_manager.getIDOfObjects(orders_manager.getProposalsToClient(client_id));
        auto result = UserInteraction::processOptions(proposals, [](std::string proposal) {
            UserInteraction::printProposalInfo(proposal);
        });
        std::string proposal_id = result.getType();
        if (proposal_id.empty()) return false;
        orders_manager.acceptProposal(proposal_id);
        if (next_handler_) return BaseHandler::handle(request);
        else return true;
    } else  {
        return BaseHandler::handle(request);
    }
}