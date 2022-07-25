#pragma once 

#include "BaseHandler.h"

class PersonSignUpHandler: public BaseHandler {
public:
    explicit PersonSignUpHandler();
    bool handle(const Request& request) override;
};
