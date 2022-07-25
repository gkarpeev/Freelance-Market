#pragma once

#include "Handler.h"
#include <memory>

class BaseHandler: public Handler {
protected:
    std::shared_ptr<Handler> next_handler_;

public:
    explicit BaseHandler();
    std::shared_ptr<Handler> setNext(std::shared_ptr<Handler> handler) override;
    bool handle(const Request& request) override;
    virtual ~BaseHandler() = default;
};
