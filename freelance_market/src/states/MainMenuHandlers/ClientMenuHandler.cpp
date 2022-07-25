#include "ClientMenuHandler.h"
#include "ShowMyOrdersHandler.h"
#include "ShowProposalsHandler.h"
#include "CreateOrderHandler.h"
#include "LogOutHandler.h"
#include "UserInteraction.h"
#include <iostream>

ClientMenuHandler::ClientMenuHandler() {}

bool ClientMenuHandler::handle(const Request& request) {
    if (request.getType() == RequestType::MENU && request.get(UserType::USER) == UserType::CLIENT) {
        // std::cerr << "[DEBUG] " << "ClientMenuHandler" << std::endl;
        std::vector<std::string> options = {
            RequestType::SHOW_MY_ORDERS,
            RequestType::SHOW_PROPOSALS_TO_MY_ORDERS,
            RequestType::CREATE_ORDER,
            RequestType::LOG_OUT
        };
        Request new_request = UserInteraction::processOptions(options, [](std::string option) {
            std::cout << option << std::endl;
        });
        return buildHandlersChain(ShowMyOrdersHandler(), ShowProposalsHandler(), 
                                       CreateOrderHandler(), LogOutHandler())->handle(new_request);
    } else {
        return BaseHandler::handle(request);
    }
}