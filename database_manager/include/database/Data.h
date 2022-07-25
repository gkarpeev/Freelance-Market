#pragma once

#include "DataType.h"
#include <string>
#include <unordered_map>
#include <vector>
#include <memory>

class Data {
private:
    std::shared_ptr<DataType> data_types_;
    std::unordered_map<std::string, std::string> values_;

public:
    Data(const Data& other) = default;
    Data(std::shared_ptr<DataType> data_types, const std::vector<std::pair<std::string, std::string>>& row_data);

    std::unordered_map<std::string, std::string>::const_iterator findColumn(const std::string& column_name) const;
    bool columnExist(const std::string& column_name) const;
    void addColumn(const std::string& column_name, const std::string& column_value);
    void removeColumn(const std::string& column_name);
    std::string getColumnValue(const std::string& column_name) const;
    std::string getColumnType(const std::string& column_name) const;
    std::vector<std::pair<std::string, std::string>> getRowData() const;
    bool operator==(const Data& other_data) const;
    bool operator!=(const Data& other_data) const;

    ~Data() = default;
};