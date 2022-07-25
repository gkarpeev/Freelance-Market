#pragma once 

#include "BaseHandler.h"

class AuthorizationHandler: public BaseHandler {
public:
    explicit AuthorizationHandler();
    bool handle(const Request& request) override;
};
