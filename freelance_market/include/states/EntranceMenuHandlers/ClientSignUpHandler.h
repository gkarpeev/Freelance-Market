#pragma once 

#include "BaseHandler.h"

class ClientSignUpHandler: public BaseHandler {
public:
    explicit ClientSignUpHandler();
    bool handle(const Request& request) override;
};
