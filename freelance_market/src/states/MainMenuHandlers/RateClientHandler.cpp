#include "RateClientHandler.h"
#include "UserInteraction.h"
#include "OrdersManager.h"
#include "FreelanceMarket.h"
#include "RatingManager.h"
#include "UserInteraction.h"
#include <iostream>

extern FreelanceMarket freelance_market;
extern OrdersManager orders_manager;
extern RatingManager rating_manager;

RateClientHandler::RateClientHandler() {}

bool RateClientHandler::handle(const Request& request) {
    if (request.getType() == RequestType::RATE_CLIENT) {
        // std::cerr << "[DEBUG] " << "RateClientHandler" << std::endl;
        std::string freelancer_id = freelance_market.getUser().getUserId();
        auto orders = orders_manager.getIDOfObjects(orders_manager.getFreelancerOrders(freelancer_id));
        auto result = UserInteraction::processOptions(orders, [](std::string order) {
            UserInteraction::printOrderInfo(order);
        });
        std::string order_id = result.getType();
        if (order_id.empty()) return false;
        std::vector<std::string> requested_data = {
            "Mark"
        };
        Request new_request = UserInteraction::getUserData(requested_data);
        int rating = std::stoi(new_request.get("Mark"));
        rating_manager.rateClient(order_id, rating);
        if (next_handler_) return BaseHandler::handle(request);
        else return true;
    } else  {
        return BaseHandler::handle(request);
    }
}