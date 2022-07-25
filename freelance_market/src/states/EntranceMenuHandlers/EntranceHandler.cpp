#include "EntranceHandler.h"
#include "LogInHandler.h"
#include "SignUpHandler.h"

// 
// CLASS EntranceHandler STARTS
//

EntranceHandler::EntranceHandler() {
    next_handler_ = buildHandlersChain(LogInHandler(), SignUpHandler());
}

bool EntranceHandler::handle(const Request& request) {
    return BaseHandler::handle({RequestType::LOG_IN});
}

// 
// CLASS EntranceHandler ENDS
//