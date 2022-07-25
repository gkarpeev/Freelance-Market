#pragma once 

#include "BaseHandler.h"

class AcceptProposalHandler: public BaseHandler {
public:
    explicit AcceptProposalHandler();
    bool handle(const Request& request) override;
};