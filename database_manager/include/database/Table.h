#pragma once

#include "Data.h"
#include "DataType.h"
#include "Filter.h"
#include <string>
#include <unordered_map>
#include <vector>
#include <memory>

class Table {
private:
    std::shared_ptr<DataType> types_of_columns_;
    std::vector<std::shared_ptr<Data>> data_;
    std::string tb_name_;

public:
    Table(std::string tb_name, DataType columns_types);

    void addColumn(std::string column_name, std::string column_type, std::string column_value);
    void removeColumn(std::string column_name);
    std::vector<std::shared_ptr<Data>>::const_iterator findData(std::shared_ptr<Data> data) const; 
    void insertData(std::shared_ptr<Data> data);
    void eraseData(std::shared_ptr<Data> data);
    void updateData(std::shared_ptr<Data> data, std::shared_ptr<Data> new_data);
    std::vector<std::shared_ptr<Data>> select(const Filter& filter, size_t from_index, 
                                              size_t to_index, bool sorted, 
                                              std::string column_name_to_sort_by) const;
    std::string getTableName() const;

    ~Table() = default;
};