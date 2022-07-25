#pragma once 

#include "BaseHandler.h"

class EntranceHandler: public BaseHandler {
public:
    explicit EntranceHandler();
    bool handle(const Request& request) override;
};
