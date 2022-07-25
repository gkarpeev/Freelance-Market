#pragma once 

#include "BaseHandler.h"

class ShowAvailableOrdersHandler: public BaseHandler {
public:
    explicit ShowAvailableOrdersHandler();
    bool handle(const Request& request) override;
};
