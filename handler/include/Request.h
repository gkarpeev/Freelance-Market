#pragma once

#include <string>
#include <unordered_map>

namespace RequestType {

const std::string SIGN_UP = "Sign Up";
const std::string LOG_IN = "Log In";
const std::string CLIENT_LOG_IN = "Log In as a Client";
const std::string FREELANCER_LOG_IN = "Log In as a Freelancer";
const std::string ENTER_ACCOUNT = "Log in";
const std::string CREATE_ACCOUNT = "Create my account";
const std::string CLIENT_SIGN_UP = "Join as a Client";
const std::string FREELANCER_SIGN_UP = "Apply as a Freelancer";
const std::string COMPANY_SIGN_UP = "Join as a Company";
const std::string PERSON_SIGN_UP = "Join as a Person";
const std::string MENU = "Back to menu";
const std::string SHOW_MY_ORDERS = "See all postings";
const std::string RATE_FREELANCER = "Rate Freelancer";
const std::string SHOW_PROPOSALS_TO_MY_ORDERS = "See all proposals";
const std::string CREATE_ORDER = "Post a Job";
const std::string LOG_OUT = "Log Out";
const std::string ACCEPT_PROPOSAL = "Accept proposal";
const std::string DECLINE_PROPOSAL = "Decline proposal";
const std::string SHOW_MY_PROPOSALS = "See my proposals";
const std::string SHOW_TAKEN_ORDERS = "See my tasks";
const std::string COMPLETE_ORDER = "Complete Order";
const std::string RATE_CLIENT = "Rate Client";
const std::string SHOW_AVAILABLE_ORDERS = "See all available orders";
const std::string CREATE_PROPOSAL = "Post a Proposal";

};

class Request {
private:
    std::string type_;
    std::unordered_map<std::string, std::string> content_;

public:
    Request() = default;
    Request(const Request& other) = default;
    Request(const std::string& type, const std::unordered_map<std::string, std::string>& content = {});
    Request& operator=(const Request& other);
    bool keyIsSet(const std::string& key) const;
    void set(const std::string& key, const std::string& value);
    void setType(const std::string& type);
    std::unordered_map<std::string, std::string> getContent() const;
    std::string getType() const;
    std::string get(const std::string& key) const;
    ~Request() = default;
};

std::ostream& operator<<(std::ostream& out, const Request& request);
