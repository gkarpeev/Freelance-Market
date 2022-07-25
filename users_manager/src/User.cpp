#include "User.h"

//
// CLASS User STARTS
//

User::User(std::string user_id, const std::string& user_type): user_id_(user_id), user_type_(user_type) {}

std::string User::getUserId() {
    return user_id_;
}

std::string User::getUserType() {
    return user_type_;
}

// 
// CLASS User ENDS
//
