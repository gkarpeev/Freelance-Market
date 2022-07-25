#pragma once

#include "Request.h"
#include <memory>

class Handler {
public:
    virtual std::shared_ptr<Handler> setNext(std::shared_ptr<Handler> handler) = 0;
    virtual bool handle(const Request& request) = 0;
};

template<typename T, typename U = Handler, typename... Args>
std::shared_ptr<U> createHandler(Args... args) {
    return std::dynamic_pointer_cast<U>(
        std::make_shared<T>(args...)
    );
}

template<typename T>
std::shared_ptr<Handler> buildHandlersChain(const T& a) {
    return createHandler<T>(a);
}

template<typename T, typename U, typename... Args>
std::shared_ptr<Handler> buildHandlersChain(const T& a, const U& b, const Args&... args) {
    std::shared_ptr<Handler> tmp = createHandler<T>(a);
    tmp->setNext(buildHandlersChain(b, args...));
    return tmp;
}
