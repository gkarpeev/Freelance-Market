#pragma once 

#include "BaseHandler.h"

class ShowMyProposalsHandler: public BaseHandler {
public:
    explicit ShowMyProposalsHandler();
    bool handle(const Request& request) override;
};
