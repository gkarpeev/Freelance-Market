#include "EntranceMenu.h"
#include "MainMenu.h"
#include "EntranceHandler.h"
#include "FreelanceMarket.h"

// 
// CLASS EntranceMenu STARTS
//

EntranceMenu::EntranceMenu() {
    handler_ = createHandler<EntranceHandler>();
}

void EntranceMenu::setNextState(std::shared_ptr<State> next_state) {
    next_state_ = next_state;
}

void EntranceMenu::switchState(FreelanceMarket* market) {
    market->setState(next_state_);
    market->setDirection(next_direction_);
}

std::string EntranceMenu::getStringState() {
    return "EntranceMenu";
}

void EntranceMenu::work() {
    if (handler_->handle(Request())) {
        next_state_ = std::make_shared<MainMenu>();
    } else {
        next_state_ = std::make_shared<EntranceMenu>();
    }
}

// 
// CLASS EntranceMenu ENDS
//