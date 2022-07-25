#pragma once

#include <string>
#include <unordered_map>
#include <vector>

class DataType {
private:
    std::unordered_map<std::string, std::string> types_of_columns_;

public:
    DataType(const DataType& other) = default;
    DataType(const std::vector<std::pair<std::string, std::string>>& row_data_type);

    std::unordered_map<std::string, std::string>::const_iterator findColumn(const std::string& column_name) const;
    bool columnExist(const std::string& column_name) const;
    void addColumn(const std::string& column_name, const std::string& column_type);
    void removeColumn(const std::string& column_name);
    std::string getColumnType(const std::string& column_name) const;
    std::vector<std::pair<std::string, std::string>> getRowTypes() const;
    bool operator==(const DataType& other) const;
    bool operator!=(const DataType& other) const;

    ~DataType() = default;
};