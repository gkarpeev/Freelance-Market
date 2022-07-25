#pragma once 

#include "BaseHandler.h"

class CompanySignUpHandler: public BaseHandler {
public:
    explicit CompanySignUpHandler();
    bool handle(const Request& request) override;
};
