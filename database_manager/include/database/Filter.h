#pragma once

#include "Data.h"
#include <string>
#include <memory>
#include <vector>


class Filter {
private:
    std::vector<std::string> column_names_;
    std::vector<std::pair<std::string, std::string>> column_ranges_;

public:
    Filter(const std::vector<std::string>& column_names, 
           const std::vector<std::pair<std::string, std::string>>& column_ranges
           );
    
    bool matchesFilter(std::shared_ptr<Data> data) const;

    ~Filter() = default;
};