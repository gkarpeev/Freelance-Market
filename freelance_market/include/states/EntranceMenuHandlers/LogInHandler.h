#pragma once 

#include "BaseHandler.h"

class LogInHandler: public BaseHandler {
public:
    explicit LogInHandler();
    bool handle(const Request& request) override;
};
