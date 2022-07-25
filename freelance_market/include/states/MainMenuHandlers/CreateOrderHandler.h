#pragma once 

#include "BaseHandler.h"

class CreateOrderHandler: public BaseHandler {
public:
    explicit CreateOrderHandler();
    bool handle(const Request& request) override;
};