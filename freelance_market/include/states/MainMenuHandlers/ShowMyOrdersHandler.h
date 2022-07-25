#pragma once 

#include "BaseHandler.h"

class ShowMyOrdersHandler: public BaseHandler {
public:
    explicit ShowMyOrdersHandler();
    bool handle(const Request& request) override;
};