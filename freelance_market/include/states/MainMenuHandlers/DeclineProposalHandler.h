#pragma once 

#include "BaseHandler.h"

class DeclineProposalHandler: public BaseHandler {
public:
    explicit DeclineProposalHandler();
    bool handle(const Request& request) override;
};