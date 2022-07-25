#pragma once 

#include "BaseHandler.h"

class LogOutHandler: public BaseHandler {
public:
    explicit LogOutHandler();
    bool handle(const Request& request) override;
};
