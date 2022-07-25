#include "RatingManager.h"
#include "DatabaseManager.h"
#include "OrdersManager.h"

extern DatabaseManager database_manager;
extern OrdersManager orders_manager;

RatingManager::RatingManager() {}

double RatingManager::getRating(std::string user_id) {
    auto result = database_manager.findByID(database_manager.getUsersCollection(), user_id);
    int orders_cnt = 0;
    int rating_sum = 0;
    if (result.keyIsSet("Orders Count")) {
        orders_cnt = std::stoi(result.get("Orders Count"));
    }
    if (result.keyIsSet("Rating Sum")) {
        rating_sum = std::stoi(result.get("Rating Sum"));
    }
    double rating = 0;
    if (orders_cnt > 0) {
        rating = rating_sum * 1.0 / orders_cnt;
    }
    return rating;
}

void RatingManager::updateRating(std::string user_id, int rating) {
    auto result = database_manager.findByID(database_manager.getUsersCollection(), user_id);
    std::string orders_cnt = result.get("Orders Count");
    std::string rating_sum = result.get("Rating Sum");
    orders_cnt = std::to_string(std::stoi(orders_cnt) + 1);
    rating_sum = std::to_string(std::stoi(rating_sum) + rating);
    database_manager.updateByID(database_manager.getUsersCollection(), user_id, "Orders Count", orders_cnt, "Rating Sum", rating_sum);
}

void RatingManager::rateFreelancer(std::string order_id, int rating) {
    std::string freelancer_id = orders_manager.getFreelancerOfOrder(order_id);
    updateRating(freelancer_id, rating);    
}

void RatingManager::rateClient(std::string order_id, int rating) {
    std::string client_id = orders_manager.getClientOfOrder(order_id);
    updateRating(client_id, rating);    
}