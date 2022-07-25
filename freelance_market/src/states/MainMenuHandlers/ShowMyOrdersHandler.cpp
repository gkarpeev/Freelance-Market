#include "ShowMyOrdersHandler.h"
#include "RateFreelancerHandler.h"
#include "UserInteraction.h"
#include "FreelanceMarket.h"
#include <iostream>

extern FreelanceMarket freelance_market;

ShowMyOrdersHandler::ShowMyOrdersHandler() {}

bool ShowMyOrdersHandler::handle(const Request& request) {
    if (request.getType() == RequestType::SHOW_MY_ORDERS) {
        // std::cerr << "[DEBUG] " << "ShowMyOrdersHandler" << std::endl;

        std::string client_id = freelance_market.getUser().getUserId();
        UserInteraction::printClientOrders(client_id);

        std::vector<std::string> options = {
            RequestType::RATE_FREELANCER,
            RequestType::MENU
        };
        Request new_request = UserInteraction::processOptions(options, [](std::string option) {
            std::cout << option << std::endl;
        });
        return buildHandlersChain(RateFreelancerHandler())->handle(new_request);
    } else {
        return BaseHandler::handle(request);
    }
}