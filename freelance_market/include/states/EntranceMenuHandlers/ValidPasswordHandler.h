#pragma once 

#include "BaseHandler.h"

class ValidPasswordHandler: public BaseHandler {
public:
    explicit ValidPasswordHandler();
    bool handle(const Request& request) override;
};
