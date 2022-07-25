#include "Filter.h"

// 
// CLASS FILTER STARTS
//

Filter::Filter(const std::vector<std::string>& column_names, 
               const std::vector<std::pair<std::string, std::string>>& column_ranges
              ) : column_names_(column_names), 
                  column_ranges_(column_ranges) 
                  {}

// TODO: make error handling
bool Filter::matchesFilter(std::shared_ptr<Data> data) const {
    for (size_t i = 0; i < column_names_.size(); i++) {
        auto value = data->getColumnValue(column_names_[i]);
        auto type = data->getColumnType(column_names_[i]);
        if (type == "string") {
            if (value < column_ranges_[i].first || column_ranges_[i].second < value) return false;
        } else if (type == "int") {
            if (stoi(value) < stoi(column_ranges_[i].first) || stoi(column_ranges_[i].second) < stoi(value)) return false;
        } else if (type == "double") {
            const double eps = 1e-5;
            if (stod(value) + eps < stod(column_ranges_[i].first) || stod(column_ranges_[i].second) < stod(value) - eps) return false;
        } else {
            // error
        }
    }
    return true;
}

// 
// CLASS FILTER ENDS
//