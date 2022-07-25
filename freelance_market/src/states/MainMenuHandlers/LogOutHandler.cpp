#include "LogOutHandler.h"
#include "EntranceMenu.h"
#include "FreelanceMarket.h"
#include <iostream>

extern FreelanceMarket freelance_market;

LogOutHandler::LogOutHandler() {}

bool LogOutHandler::handle(const Request& request) {
    if (request.getType() == RequestType::LOG_OUT) {
        // std::cerr << "[DEBUG] " << "LogOutHandler" << std::endl;
        freelance_market.setNextState(std::make_shared<EntranceMenu>());
        std::cout << "Goodbye!" << std::endl;
        return true;
    } else {
        return BaseHandler::handle(request);
    }
}
