#include "MainMenuHandler.h"
#include "UserInteraction.h"
#include "ClientMenuHandler.h"
#include "FreelancerMenuHandler.h"
#include "FreelanceMarket.h"
#include "Request.h"
#include <iostream>

extern FreelanceMarket freelance_market;

MainMenuHandler::MainMenuHandler() {}

bool MainMenuHandler::handle(const Request& request) {
    // std::cerr << "[DEBUG] " << "MainMenuHandler" << std::endl;
    next_handler_ = buildHandlersChain(ClientMenuHandler(), FreelancerMenuHandler());
    Request new_request(RequestType::MENU);
    new_request.set(UserType::USER, freelance_market.getUser().getUserType());
    return BaseHandler::handle(new_request);
}
