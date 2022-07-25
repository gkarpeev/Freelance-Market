#include "CreateProposalHandler.h"
#include "OrdersManager.h"
#include "FreelanceMarket.h"
#include "UserInteraction.h"
#include <iostream>

extern FreelanceMarket freelance_market;
extern OrdersManager orders_manager;

CreateProposalHandler::CreateProposalHandler() {}

bool CreateProposalHandler::handle(const Request& request) {
    if (request.getType() == RequestType::CREATE_PROPOSAL) {
        // std::cerr << "[DEBUG] " << "CreateProposalHandler" << std::endl;
        std::string freelancer_id = freelance_market.getUser().getUserId();
        auto orders = orders_manager.getIDOfObjects(orders_manager.getAvailableOrders());
        auto result = UserInteraction::processOptions(orders, [](std::string order) {
            UserInteraction::printOrderInfo(order);
        });
        std::string order_id = result.getType();
        if (order_id.empty()) return false;
        std::vector<std::string> requested_data = {
            "Cover Letter"
        };
        Request new_request = UserInteraction::getUserData(requested_data);
        orders_manager.createProposal(freelancer_id, order_id, new_request);
        if (next_handler_) return BaseHandler::handle(request);
        else return true;
    } else {
        return BaseHandler::handle(request);
    }
}