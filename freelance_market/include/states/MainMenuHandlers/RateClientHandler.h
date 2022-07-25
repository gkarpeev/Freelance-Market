#pragma once 

#include "BaseHandler.h"

class RateClientHandler: public BaseHandler {
public:
    explicit RateClientHandler();
    bool handle(const Request& request) override;
};