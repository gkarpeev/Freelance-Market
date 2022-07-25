#include "RateFreelancerHandler.h"
#include "UserInteraction.h"
#include "OrdersManager.h"
#include "FreelanceMarket.h"
#include "RatingManager.h"
#include "UserInteraction.h"
#include <iostream>

extern FreelanceMarket freelance_market;
extern OrdersManager orders_manager;
extern RatingManager rating_manager;

RateFreelancerHandler::RateFreelancerHandler() {}

bool RateFreelancerHandler::handle(const Request& request) {
    if (request.getType() == RequestType::RATE_FREELANCER) {
        // std::cerr << "[DEBUG] " << "RateFreelancerHandler" << std::endl;
        
        std::string client_id = freelance_market.getUser().getUserId();
        auto orders = orders_manager.getIDOfObjects(orders_manager.getClientOrders(client_id));
        auto result = UserInteraction::processOptions(orders, [](std::string order) {
            UserInteraction::printOrderInfo(order);
        });
        std::string order_id = result.getType();
        if (order_id.empty()) return false;
        if (!orders_manager.checkIfFreelancerIsChosen(order_id)) {
            std::cout << "Sorry, You have not chosen Freelancer for this order!" << std::endl;
            return false;
        }
        std::vector<std::string> requested_data = {
            "Mark"
        };
        Request new_request = UserInteraction::getUserData(requested_data);
        int rating = std::stoi(new_request.get("Mark"));
        rating_manager.rateFreelancer(order_id, rating);
        if (next_handler_) return BaseHandler::handle(request);
        else return true;
    } else {
        return BaseHandler::handle(request);
    }
}