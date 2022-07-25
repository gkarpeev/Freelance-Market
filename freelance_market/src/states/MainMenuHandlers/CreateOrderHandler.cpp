#include "CreateOrderHandler.h"
#include "OrdersManager.h"
#include "FreelanceMarket.h"
#include "UserInteraction.h"
#include <iostream>

extern FreelanceMarket freelance_market;
extern OrdersManager orders_manager;

CreateOrderHandler::CreateOrderHandler() {}

bool CreateOrderHandler::handle(const Request& request) {
    if (request.getType() == RequestType::CREATE_ORDER) {
        // std::cerr << "[DEBUG] " << "CreateOrderHandler" << std::endl;
        std::vector<std::string> requested_data = {
            "Write a headline for your job post",
            "Great! What skills does your work require?",
            "Almost done! Tell us about your budget"
        };
        Request new_request = UserInteraction::getUserData(requested_data);
        std::string client_id = freelance_market.getUser().getUserId();
        orders_manager.createOrder(client_id, new_request);
        if (next_handler_) return BaseHandler::handle(request);
        else return true;
    } else {
        return BaseHandler::handle(request);
    }
}