#include "ShowAvailableOrdersHandler.h"
#include "CreateProposalHandler.h"
#include "UserInteraction.h"
#include <iostream>

ShowAvailableOrdersHandler::ShowAvailableOrdersHandler() {}

bool ShowAvailableOrdersHandler::handle(const Request& request) {
    if (request.getType() == RequestType::SHOW_AVAILABLE_ORDERS) {
        // std::cerr << "[DEBUG] " << "ShowAvailableOrdersHandler" << std::endl;

        UserInteraction::printAvailableOrders();

        std::vector<std::string> options = {
            RequestType::CREATE_PROPOSAL,
            RequestType::MENU
        };
        Request new_request = UserInteraction::processOptions(options, [](std::string option) {
            std::cout << option << std::endl;
        });
        return buildHandlersChain(CreateProposalHandler())->handle(new_request);
    } else {
        return BaseHandler::handle(request);
    }
}