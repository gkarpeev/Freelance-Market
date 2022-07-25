#pragma once 

#include "BaseHandler.h"

class ClientMenuHandler: public BaseHandler {
public:
    explicit ClientMenuHandler();
    bool handle(const Request& request) override;
};