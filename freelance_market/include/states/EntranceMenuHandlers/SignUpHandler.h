#pragma once 

#include "BaseHandler.h"

class SignUpHandler: public BaseHandler {
public:
    explicit SignUpHandler();
    bool handle(const Request& request) override;
};
