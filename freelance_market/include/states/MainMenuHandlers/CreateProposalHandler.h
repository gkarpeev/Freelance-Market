#pragma once 

#include "BaseHandler.h"

class CreateProposalHandler: public BaseHandler {
public:
    explicit CreateProposalHandler();
    bool handle(const Request& request) override;
};
