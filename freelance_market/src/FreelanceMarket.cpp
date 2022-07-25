#include "FreelanceMarket.h"
#include "EntranceMenu.h"
#include <iostream>

// 
// CLASS FreelanceMarket STARTS
//

FreelanceMarket::FreelanceMarket(): direction_(Direction::MAIN_MENU) {
    state_ = std::make_shared<EntranceMenu>();
}

void FreelanceMarket::setState(std::shared_ptr<State> state) {
    state_ = std::move(state);
}

void FreelanceMarket::setNextState(std::shared_ptr<State> state) {
    state_->setNextState(state);
}

Direction FreelanceMarket::getDirection() {
    return direction_;
}

void FreelanceMarket::setDirection(Direction direction) {
    direction_ = direction;
}

void FreelanceMarket::switchState() {
    state_->switchState(this);
}

void FreelanceMarket::printState() {
    std::cout << "[State]" << std::endl;
    std::cout << "[Direction]: " << direction_ << std::endl;
    std::cout << "[Current State]: " << state_->getStringState() << std::endl;
}

void FreelanceMarket::work() {
    while (true) {
        state_->work();
        switchState();
    }
}

void FreelanceMarket::setUser(User user) {
    current_user_ = user;
}

User FreelanceMarket::getUser() {
    return current_user_;
}

// 
// CLASS FreelanceMarket ENDS
//