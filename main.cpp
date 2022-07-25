#include "FreelanceMarket.h"
#include "DatabaseManager.h"
#include "RatingManager.h"
#include "UserManager.h"
#include "OrdersManager.h"
#include <iostream>

FreelanceMarket freelance_market;
DatabaseManager database_manager;
RatingManager rating_manager;
UserManager user_manager;
OrdersManager orders_manager;

int main() {
    std::cout << "Successfully configured\n";
    freelance_market.work();
    return 0;
}