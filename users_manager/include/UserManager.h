#pragma once

#include "Request.h"
#include <string>

class UserManager {
public:
    UserManager();
    std::string addUser(Request user_data);
    Request getUserData(std::string user_id);
    bool checkIfUserExist(Request request);
    std::string getUserID(Request request);
    bool checkValidPassword(Request request);
};
