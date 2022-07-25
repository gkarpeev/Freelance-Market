#pragma once 

#include "BaseHandler.h"

class RateFreelancerHandler: public BaseHandler {
public:
    explicit RateFreelancerHandler();
    bool handle(const Request& request) override;
};
