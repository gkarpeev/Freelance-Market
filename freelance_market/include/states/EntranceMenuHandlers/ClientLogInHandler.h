#pragma once 

#include "BaseHandler.h"

class ClientLogInHandler: public BaseHandler {
public:
    explicit ClientLogInHandler();
    bool handle(const Request& request) override;
};
