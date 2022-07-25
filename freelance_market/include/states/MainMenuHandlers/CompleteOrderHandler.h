#pragma once 

#include "BaseHandler.h"

class CompleteOrderHandler: public BaseHandler {
public:
    explicit CompleteOrderHandler();
    bool handle(const Request& request) override;
};