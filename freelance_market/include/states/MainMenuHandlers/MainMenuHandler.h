#pragma once 

#include "BaseHandler.h"

class MainMenuHandler: public BaseHandler {
public:
    explicit MainMenuHandler();
    bool handle(const Request& request) override;
};
























