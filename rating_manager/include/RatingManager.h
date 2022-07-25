#pragma once

#include <string>

class RatingManager {
public:
    RatingManager();
    void updateRating(std::string user_id, int rating);
    double getRating(std::string user_id);
    void rateFreelancer(std::string order_id, int rating);
    void rateClient(std::string order_id, int rating);
};
