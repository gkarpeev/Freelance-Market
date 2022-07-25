#pragma once

#include <string>
#include <memory>

namespace UserType {
const std::string USER = "User";
const std::string CLIENT = "Client";
const std::string COMPANY = "Company";
const std::string PERSON = "Person";
const std::string FREELANCER = "Freelancer";
}

class User {
private:
    std::string user_id_;
    std::string user_type_;

public:
    User() = default;
    User(std::string user_id, const std::string& user_type);
    std::string getUserId();
    std::string getUserType();
};
