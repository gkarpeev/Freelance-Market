#pragma once 

#include "BaseHandler.h"

class ShowProposalsHandler: public BaseHandler {
public:
    explicit ShowProposalsHandler();
    bool handle(const Request& request) override;
};