#include "BaseHandler.h"
#include <memory>

// 
// CLASS BaseHandler STARTS
//

BaseHandler::BaseHandler() {}

std::shared_ptr<Handler> BaseHandler::setNext(std::shared_ptr<Handler> handler) {
    next_handler_ = std::move(handler);
    return next_handler_;
}

bool BaseHandler::handle(const Request& request) {
    if (next_handler_) {
        return next_handler_->handle(request);
    }
    return false;
}

// 
// CLASS BaseHandler ENDS
//