#pragma once 

#include "BaseHandler.h"

class AccountCreationHandler: public BaseHandler {
public:
    explicit AccountCreationHandler();
    bool handle(const Request& request) override;
};
