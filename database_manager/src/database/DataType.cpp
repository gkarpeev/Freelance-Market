#include "DataType.h"

// 
// CLASS DATATYPE STARTS
//

DataType::DataType(const std::vector<std::pair<std::string, std::string>>& row_data_type) {
    for (auto& element : row_data_type) {
        addColumn(element.first, element.second);
    }
}

std::unordered_map<std::string, std::string>::const_iterator DataType::findColumn(const std::string& column_name) const {
    auto it = types_of_columns_.find(column_name);
    return it;
}

bool DataType::columnExist(const std::string& column_name) const {
    auto it = findColumn(column_name);
    return it != types_of_columns_.end();
}

// TODO: make error handling
void DataType::addColumn(const std::string& column_name, const std::string& column_type) {
    types_of_columns_[column_name] = column_type;
}

void DataType::removeColumn(const std::string& column_name) {
    auto it = findColumn(column_name);
    if (it != types_of_columns_.end()) {
        types_of_columns_.erase(it);
    }
}

// TODO: make error handling
std::string DataType::getColumnType(const std::string& column_name) const {
    auto it = findColumn(column_name);
    if (it != types_of_columns_.end()) {
        return it->second;
    }
    return "Error";
}

std::vector<std::pair<std::string, std::string>> DataType::getRowTypes() const {
    std::vector<std::pair<std::string, std::string>> data_types;
    for (auto& element : types_of_columns_) {
        data_types.push_back(element);
    }
    return data_types;
}

bool DataType::operator==(const DataType& other) const {
    return types_of_columns_ == other.types_of_columns_;
}

bool DataType::operator!=(const DataType& other) const {
    return !(*this == other);
}


// 
// CLASS DATATYPE ENDS
//