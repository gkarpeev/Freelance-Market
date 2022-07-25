#pragma once 

#include "BaseHandler.h"

class ShowTakenOrdersHandler: public BaseHandler {
public:
    explicit ShowTakenOrdersHandler();
    bool handle(const Request& request) override;
};