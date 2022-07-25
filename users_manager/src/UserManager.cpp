#include "UserManager.h"
#include "DatabaseManager.h"
#include <unordered_set>

extern DatabaseManager database_manager;

UserManager::UserManager() {}

std::string UserManager::addUser(Request user_data) {
    std::unordered_set<std::string> possible_options = {"First Name", "Last Name", "Email", "Password", "Country", "User", "Orders Count", "Rating Sum"};
    user_data.set("Orders Count", "0");
    user_data.set("Rating Sum", "0");
    return database_manager.add(database_manager.getUsersCollection(), user_data, possible_options);
}

Request UserManager::getUserData(std::string user_id) {
    return database_manager.findByID(database_manager.getUsersCollection(), user_id);
}

bool UserManager::checkIfUserExist(Request request) {
    return database_manager.findManyByMultipleParameters(database_manager.getUsersCollection(), "Email", request.get("Email")).size() != 0;
}

std::string UserManager::getUserID(Request request) {
    auto result = database_manager.findManyByMultipleParameters(database_manager.getUsersCollection(), "Email", request.get("Email"));
    if (result.size() > 0) {
        return result[0].get("_id");
    }
    return "";
}

bool UserManager::checkValidPassword(Request request) {
    auto result = database_manager.findManyByMultipleParameters(database_manager.getUsersCollection(), "Email", request.get("Email"));
    if (result.size() > 0 && result[0].get("Password") == request.get("Password")) {
        return true;
    }
    return false;
}
