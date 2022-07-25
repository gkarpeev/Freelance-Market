#include "UserInteraction.h"
#include "RatingManager.h"
#include "OrdersManager.h"
#include "UserManager.h"
#include <iostream>
#include <iomanip>
#include <unordered_set>
#include <algorithm>

extern RatingManager rating_manager;
extern OrdersManager orders_manager;
extern UserManager user_manager;

//
// CLASS UserInteraction STARTS
//

UserInteraction::UserInteraction() {}

UserInteraction* UserInteraction::instance_ = nullptr;

UserInteraction* UserInteraction::getInstance() {
    if (instance_ == nullptr) {
        instance_ = new UserInteraction;
    }
    return instance_;
}

void UserInteraction::destroyInstance() {
    delete instance_;
    instance_ = nullptr;
}

UserInteraction::~UserInteraction() {}

Request UserInteraction::processOptions(const std::vector<std::string>& allowed_options = {}, 
        std::function<void(std::string)> printer = [](std::string option) {
            std::cout << option << std::endl;
        }) {
    if (allowed_options.size() == 0) {
        std::cout << "NO possible options!" << std::endl;
        return Request();
    }
    Request new_request;
    while (true) {
        std::cout << std::endl;
        std::cout << "Select option: " << std::endl;
        std::vector<std::string> out;
        for (auto& allowed_option : allowed_options) { 
            std::cout << out.size() + 1 << ". ";
            printer(allowed_option);
            out.push_back(allowed_option);
        }
        std::cout << "Select: [1" << ".." << out.size() << "]" << std::endl;
        std::cout << std::endl;
        std::string option;
        std::cin >> option;
        if (!option.empty() && std::all_of(option.begin(), option.end(), ::isdigit) && 1 <= stoi(option) && stoi(option) <= out.size()) {
            int option_id = stoi(option);
            new_request = {
                out[option_id - 1]
            };
            break;
        } else if (!option.empty()) {
            std::cout << "Error: Invalid option!" << std::endl;
        }
    }
    return new_request;
}

Request UserInteraction::getUserData(const std::vector<std::string>& requested_data) {
    Request request;
    for (auto& key: requested_data) {
        std::cout << key << ": ";
        std::string value;
        std::cin >> value;
        request.set(key, value);
    }
    return request;
}

void UserInteraction::printUserInfo(std::string user_id, std::string user_type) {
    auto result = user_manager.getUserData(user_id);
    std::cout << "[USER]: " << user_type << std::endl;
    std::vector<std::string> user_info = {"First Name", "Last Name", "Email", "Country", "User"};
    for (auto &option : user_info) {
        if (result.keyIsSet(option)) {
            std::cout << "[" << option << "]: " << result.get(option) << std::endl;
        }
    }
    std::cout << "[RATING]: " << std::fixed << std::setprecision(2) << rating_manager.getRating(user_id) << std::endl;
    std::cout << std::endl;
}

void UserInteraction::printOrderInfo(std::string order_id) {
    std::cout << "[ORDER INFO]" << std::endl;
    auto result = orders_manager.getOrderData(order_id);
    if (result.keyIsSet("Write a headline for your job post")) {
        std::cout << "[Job Headline]: " << result.get("Write a headline for your job post") << std::endl;
    }
    if (result.keyIsSet("Client ID")) {
        printUserInfo(result.get("Client ID"), "Client");
    }
    if (result.keyIsSet("Freelancer ID")) {
        printUserInfo(result.get("Freelancer ID"), "Freelancer");
    }
    if (result.keyIsSet("Status")) {
        std::cout << "[Order Status]: " << result.get("Status") << std::endl;
    }
    std::cout << std::endl;
}

void UserInteraction::printAvailableOrders() {
    auto orders = orders_manager.getIDOfObjects(orders_manager.getAvailableOrders());
    std::cout << "Available Orders Found: " << orders.size() << std::endl;
    int cnt = 0;
    for (auto &el : orders) {
        std::cout << ++cnt << ". ";
        printOrderInfo(el);
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void UserInteraction::printClientOrders(std::string client_id) {
    auto orders = orders_manager.getIDOfObjects(orders_manager.getClientOrders(client_id));
    std::cout << "Client Orders Found: " << orders.size() << std::endl;
    int cnt = 0;
    for (auto &el : orders) {
        std::cout << ++cnt << ". ";
        printOrderInfo(el);
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void UserInteraction::printFreelancerOrders(std::string freelancer_id) {
    auto orders = orders_manager.getIDOfObjects(orders_manager.getFreelancerOrders(freelancer_id));
    std::cout << "Freelancer Orders Found: " << orders.size() << std::endl;
    int cnt = 0;
    for (auto &el : orders) {
        std::cout << ++cnt << ". ";
        printOrderInfo(el);
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void UserInteraction::printProposalInfo(std::string proposal_id) {
    auto result = orders_manager.getProposalData(proposal_id);
    std::cout << "[PROPOSAL INFO]" << std::endl;
    if (result.keyIsSet("Order ID")) {
        printOrderInfo(result.get("Order ID"));
    }
    if (result.keyIsSet("Freelancer ID")) {
        printUserInfo(result.get("Freelancer ID"), "Freelancer");
    }
    if (result.keyIsSet("Status")) {
        std::cout << "[Proposal Status]: " << result.get("Status") << std::endl;
    }
    std::cout << std::endl;
}

void UserInteraction::printFreelancerProposals(std::string freelancer_id) {
    auto proposals = orders_manager.getIDOfObjects(orders_manager.getFreelancerProposals(freelancer_id));
    std::cout << "Freelancer Proposals Found: " << proposals.size() << std::endl;
    int cnt = 0;
    for (auto &el : proposals) {
        std::cout << ++cnt << ": ";
        printProposalInfo(el);
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void UserInteraction::printProposalsToClient(std::string client_id) {
    auto proposals = orders_manager.getIDOfObjects(orders_manager.getProposalsToClient(client_id));
    std::cout << "Proposal To Client Found: " << proposals.size() << std::endl;
    int cnt = 0;
    for (auto &el : proposals) {
        std::cout << ++cnt << ": ";
        printProposalInfo(el);
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

// 
// CLASS UserInteraction ENDS
//
