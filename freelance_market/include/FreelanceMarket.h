#pragma once

#include "Handler.h"
#include "State.h"
#include "User.h"
#include <memory>

class State;
enum class Direction;

class FreelanceMarket {
private:
    std::shared_ptr<State> state_;
    Direction direction_;
    User current_user_;

public:
    FreelanceMarket();
    void setState(std::shared_ptr<State>);
    void setNextState(std::shared_ptr<State>);
    Direction getDirection();
    void setDirection(Direction direction);
    void switchState();
    void printState();
    void work();
    void setUser(User user);
    User getUser();
};
