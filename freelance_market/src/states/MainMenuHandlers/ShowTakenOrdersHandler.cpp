#include "ShowTakenOrdersHandler.h"
#include "CompleteOrderHandler.h"
#include "RateClientHandler.h"
#include "UserInteraction.h"
#include "FreelanceMarket.h"
#include <iostream>

extern FreelanceMarket freelance_market;

ShowTakenOrdersHandler::ShowTakenOrdersHandler() {}

bool ShowTakenOrdersHandler::handle(const Request& request) {
    if (request.getType() == RequestType::SHOW_TAKEN_ORDERS) {
        // std::cerr << "[DEBUG] " << "ShowTakenOrdersHandler" << std::endl;
        
        std::string freelancer_id = freelance_market.getUser().getUserId();
        UserInteraction::printFreelancerOrders(freelancer_id);

        std::vector<std::string> options = {
            RequestType::COMPLETE_ORDER,
            RequestType::RATE_CLIENT,
            RequestType::MENU
        };
        Request new_request = UserInteraction::processOptions(options, [](std::string option) {
            std::cout << option << std::endl;
        });
        return buildHandlersChain(CompleteOrderHandler(), RateClientHandler())->handle(new_request);
    } else {
        return BaseHandler::handle(request);
    }
}