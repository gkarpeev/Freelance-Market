#include "MainMenu.h"
#include "MainMenuHandler.h"
#include "FreelanceMarket.h"
#include <iostream>

// 
// CLASS MainMenu STARTS
//

MainMenu::MainMenu() {
    std::cout << std::endl << "Now you are in Main Menu!" << std::endl;
    handler_ = createHandler<MainMenuHandler>();
}

void MainMenu::setNextState(std::shared_ptr<State> next_state) {
    next_state_ = next_state;
}

void MainMenu::switchState(FreelanceMarket* market) {
    market->setState(next_state_);
    market->setDirection(next_direction_);
}

std::string MainMenu::getStringState() {
    return "MainMenu";
}

void MainMenu::work() {
    next_state_ = nullptr;
    handler_->handle(Request());
    if (next_state_ == nullptr) {
        next_state_ = std::make_shared<MainMenu>();
    }
}

// 
// CLASS MainMenu ENDS
//