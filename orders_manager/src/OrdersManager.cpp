#include "OrdersManager.h"
#include "DatabaseManager.h"
#include <unordered_set>

extern DatabaseManager database_manager;

// namespace ID {
// const std::string CLIENT_ID = "Client ID";
// const std::string FREELANCER_ID = "Freelancer ID";
// const std::string ORDER_ID = "Client ID";
// const std::string PROPOSAL_ID = "Proposal ID";
// };

// namespace OrderStatus {
// const std::string NOT_STARTED = "Not started";
// const std::string IN_PROGRESS = "In progress";
// const std::string COMPLETED = "Completed";
// };

// namespace ProposalStatus {
// const std::string PENDING = "Pending";
// const std::string ACCEPTED = "Accepted";
// const std::string DECLINED = "Declined";
// };

OrdersManager::OrdersManager() {}

std::string OrdersManager::createOrder(std::string user_id, Request request) {
    std::unordered_set<std::string> possible_options = {"Write a headline for your job post", "Great! What skills does your work require?", "Almost done! Tell us about your budget", "Client ID", "Status"};
    request.set("Client ID", user_id);
    request.set("Status", "Not started");
    return database_manager.add(database_manager.getOrdersCollection(), request, possible_options);
}

std::string OrdersManager::createProposal(std::string freelancer_id, std::string order_id, Request request) {
    auto result = database_manager.findByID(database_manager.getOrdersCollection(), order_id);
    std::string client_id = result.get("Client ID");
    std::unordered_set<std::string> possible_options = {"Cover Letter", "Order ID", "Client ID", "Freelancer ID", "Status"};
    request.set("Order ID", order_id);
    request.set("Client ID", client_id);
    request.set("Freelancer ID", freelancer_id);
    request.set("Status", "Pending");
    return database_manager.add(database_manager.getProposalsCollection(), request, possible_options);
}

void OrdersManager::acceptProposal(std::string proposal_id) {
    database_manager.updateByID(database_manager.getProposalsCollection(), proposal_id, "Status", "Accepted");
    auto result = database_manager.findByID(database_manager.getProposalsCollection(), proposal_id);
    std::string order_id = result.get("Order ID");
    std::string freelancer_id = result.get("Freelancer ID");
    database_manager.updateByID(database_manager.getOrdersCollection(), order_id, "Status", "In progress", "Freelancer ID", freelancer_id);
}

void OrdersManager::declineProposal(std::string proposal_id) {
    database_manager.updateByID(database_manager.getProposalsCollection(), proposal_id, "Status", "Declined");
}

void OrdersManager::completeOrder(std::string order_id) {
    database_manager.updateByID(database_manager.getOrdersCollection(), order_id, "Status", "Completed");
}

std::string OrdersManager::getClientOfOrder(std::string order_id) {
    return database_manager.findByID(database_manager.getOrdersCollection(), order_id).get("Client ID");
}

std::string OrdersManager::getFreelancerOfOrder(std::string order_id) {
    return database_manager.findByID(database_manager.getOrdersCollection(), order_id).get("Freelancer ID");
}

Request OrdersManager::getOrderData(std::string order_id) {
    return database_manager.findByID(database_manager.getOrdersCollection(), order_id);
}

Request OrdersManager::getProposalData(std::string proposal_id) {
    return database_manager.findByID(database_manager.getProposalsCollection(), proposal_id);
}

std::vector<Request> OrdersManager::getAvailableOrders() {
    return database_manager.findManyByMultipleParameters(database_manager.getOrdersCollection(), "Status", "Not started");
}

std::vector<Request> OrdersManager::getClientOrders(std::string user_id) {
    return database_manager.findManyByMultipleParameters(database_manager.getOrdersCollection(), "Client ID", user_id);
}

std::vector<Request> OrdersManager::getFreelancerOrders(std::string user_id) {
    return database_manager.findManyByMultipleParameters(database_manager.getOrdersCollection(), "Freelancer ID", user_id);
}

std::vector<Request> OrdersManager::getFreelancerProposals(std::string user_id) {
    return database_manager.findManyByMultipleParameters(database_manager.getProposalsCollection(), "Freelancer ID", user_id);
}

std::vector<Request> OrdersManager::getProposalsToClient(std::string user_id) {
    return database_manager.findManyByMultipleParameters(database_manager.getProposalsCollection(), "Client ID", user_id, "Status", "Pending");
}

std::vector<std::string> OrdersManager::getIDOfObjects(const std::vector<Request>& objects) {
    std::vector<std::string> orders = {};
    for (auto &el : objects) {
        orders.push_back(el.get("_id"));
    }
    return orders;
}

bool OrdersManager::checkIfFreelancerIsChosen(std::string order_id) {
    return getOrderData(order_id).keyIsSet("Freelancer ID");
}