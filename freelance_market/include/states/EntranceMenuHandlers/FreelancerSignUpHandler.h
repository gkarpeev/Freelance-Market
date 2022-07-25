#pragma once 

#include "BaseHandler.h"

class FreelancerSignUpHandler: public BaseHandler {
public:
    explicit FreelancerSignUpHandler();
    bool handle(const Request& request) override;
};
