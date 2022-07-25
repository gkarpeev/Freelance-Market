#pragma once

#include "State.h"

class MainMenu: public State {
private:
    std::shared_ptr<Handler> handler_;
    std::shared_ptr<State> next_state_;
    Direction next_direction_;

public:
    MainMenu();
    void setNextState(std::shared_ptr<State> next_state) override;
    void switchState(FreelanceMarket* market) override; 
    std::string getStringState() override;
    void work() override;
};