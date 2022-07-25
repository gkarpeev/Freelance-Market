#pragma once

#include "User.h"
#include "Request.h"
#include <memory>
#include <vector>
#include <functional>

class UserInteraction {
private:
    UserInteraction();
    static UserInteraction* instance_;
    static std::shared_ptr<User> user_;

public:
    UserInteraction(const UserInteraction& other) = delete;
    void operator=(const UserInteraction& other) = delete;

    static UserInteraction* getInstance();
    static void destroyInstance();

    static Request processOptions(const std::vector<std::string>& allowed_options, std::function<void(std::string)> printer);
    static Request getUserData(const std::vector<std::string>& requested_data);
    static void printUserInfo(std::string user_id, std::string user_type);
    static void printOrderInfo(std::string order_id);
    static void printAvailableOrders();
    static void printClientOrders(std::string client_id);
    static void printFreelancerOrders(std::string freelancer_id);
    static void printProposalInfo(std::string proposal_id);
    static void printFreelancerProposals(std::string freelancer_id);
    static void printProposalsToClient(std::string client_id);
    ~UserInteraction();
};
