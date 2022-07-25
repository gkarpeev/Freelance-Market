#include "Data.h"

// 
// CLASS DATA STARTS
//


Data::Data(std::shared_ptr<DataType> data_types, const std::vector<std::pair<std::string, std::string>>& row_data) : data_types_(data_types) {
    for (auto& element : row_data) {
        addColumn(element.first, element.second);
    }
}

std::unordered_map<std::string, std::string>::const_iterator Data::findColumn(const std::string& column_name) const {
    auto it = values_.find(column_name);
    return it;
}

bool Data::columnExist(const std::string& column_name) const {
    auto it = findColumn(column_name);
    return it != values_.end();
}

// TODO: make error handling
void Data::addColumn(const std::string& column_name, const std::string& column_type) {
    values_[column_name] = column_type;
}

void Data::removeColumn(const std::string& column_name) {
    auto it = findColumn(column_name);
    if (it != values_.end()) {
        values_.erase(it);
    }
}

// todo: make error handling
std::string Data::getColumnValue(const std::string& column_name) const {
    auto it = findColumn(column_name);
    if (it != values_.end()) {
        return it->second;
    }
    return "Error";
}

std::string Data::getColumnType(const std::string& column_name) const {
    return data_types_->getColumnType(column_name);
}

std::vector<std::pair<std::string, std::string>> Data::getRowData() const {
    std::vector<std::pair<std::string, std::string>> data;
    for (auto& element : values_) {
        data.push_back(element);
    }
    return data;
}

bool Data::operator==(const Data& other_data) const {
    return *data_types_ == *other_data.data_types_ && values_ == other_data.values_;
}

bool Data::operator!=(const Data& other_data) const {
    return !(*this == other_data);
}

// 
// CLASS DATA ENDS
//
