#pragma once 

#include "BaseHandler.h"

class FreelancerMenuHandler: public BaseHandler {
public:
    explicit FreelancerMenuHandler();
    bool handle(const Request& request) override;
};
