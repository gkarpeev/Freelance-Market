#pragma once 

#include "BaseHandler.h"

class UserExistHandler: public BaseHandler {
public:
    explicit UserExistHandler();
    bool handle(const Request& request) override;
};
