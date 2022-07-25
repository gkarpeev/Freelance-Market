#pragma once

#include "Request.h"
#include <iostream>
#include <vector>

class OrdersManager {
public:
    OrdersManager();
    // Returns Order ID
    std::string createOrder(std::string user_id, Request request);
    // Returns Proposal ID
    std::string createProposal(std::string freelancer_id, std::string order_id, Request request);
    void acceptProposal(std::string proposal_id);
    void declineProposal(std::string proposal_id);
    void completeOrder(std::string order_id);
    Request getOrderData(std::string order_id);
    Request getProposalData(std::string proposal_id);
    std::string getClientOfOrder(std::string order_id);
    std::string getFreelancerOfOrder(std::string order_id);
    std::vector<Request> getAvailableOrders();
    std::vector<Request> getClientOrders(std::string user_id);
    std::vector<Request> getFreelancerOrders(std::string user_id);
    std::vector<Request> getUserProposals(std::string user_id);
    std::vector<Request> getFreelancerProposals(std::string user_id);
    std::vector<Request> getProposalsToClient(std::string user_id);
    std::vector<std::string> getIDOfObjects(const std::vector<Request>& objects);
    bool checkIfFreelancerIsChosen(std::string order_id);
};
