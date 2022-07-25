#include "CompleteOrderHandler.h"
#include "OrdersManager.h"
#include "FreelanceMarket.h"
#include "UserInteraction.h"
#include <iostream>

extern FreelanceMarket freelance_market;
extern OrdersManager orders_manager;

CompleteOrderHandler::CompleteOrderHandler() {}

bool CompleteOrderHandler::handle(const Request& request) {
    if (request.getType() == RequestType::COMPLETE_ORDER) {
        // std::cerr << "[DEBUG] " << "CompleteOrderHandler" << std::endl;
        std::string freelancer_id = freelance_market.getUser().getUserId();
        auto orders = orders_manager.getIDOfObjects(orders_manager.getFreelancerOrders(freelancer_id));
        auto result = UserInteraction::processOptions(orders, [](std::string order) {
            UserInteraction::printOrderInfo(order);
        });
        std::string order_id = result.getType();
        if (order_id.empty()) return false;
        orders_manager.completeOrder(order_id);
        if (next_handler_) return BaseHandler::handle(request);
        else return true;
    } else  {
        return BaseHandler::handle(request);
    }
}