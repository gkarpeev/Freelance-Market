#pragma once

#include "FreelanceMarket.h"
#include <memory>

enum class Direction {
    ENTRANCE_MENU,
    MAIN_MENU
};

std::ostream& operator<<(std::ostream& out, const Direction& direction);

namespace std {

template <>
struct hash<Direction> {
    size_t operator()(const Direction& direction) const {
        return static_cast<size_t>(direction);
    }
};

}

class FreelanceMarket;

class State {
public:
    virtual void setNextState(std::shared_ptr<State>) = 0;
    virtual void switchState(FreelanceMarket* market) = 0;
    virtual std::string getStringState() = 0;
    virtual void work() = 0;
};
