#pragma once 

#include "BaseHandler.h"

class FreelancerLogInHandler: public BaseHandler {
public:
    explicit FreelancerLogInHandler();
    bool handle(const Request& request) override;
};
