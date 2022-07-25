#pragma once

#include "Table.h"
#include "DataType.h"
#include "Data.h"
#include <vector>
#include <string>
#include <unordered_map>
#include <memory>
#include <set>
#include <algorithm>

class Database {
private:
    Database();
    static Database* database_;
    std::string db_name_;

    std::unordered_map<std::string, std::shared_ptr<Table>> tables_;

public:
    Database(const Database& other) = delete;
    void operator=(const Database& other) = delete;

    static Database* getInstance(const std::string& db_name);
    static void destroyInstance();

    std::shared_ptr<Table> getTable(const std::string& tb_name) const;
    std::string getDatabaseName() const;
    void createTable(const std::string& tb_name, const DataType& columns_types);
    std::unordered_map<std::string, std::shared_ptr<Table>>::const_iterator findTable(const std::string& tb_name) const;
    bool tableExist(const std::string& tb_name) const;
    void addColumnToTable(std::string tb_name, std::string column_name, std::string column_type, std::string column_value);
    void removeColumnFromTable(std::string tb_name, std::string column_name);
    std::vector<std::shared_ptr<Data>>::const_iterator findDataInTable(std::string tb_name, std::shared_ptr<Data> data) const; 
    void insertDataInTable(std::string tb_name, std::shared_ptr<Data> data);
    void eraseDataInTable(std::string tb_name, std::shared_ptr<Data> data);
    void updateDataInTable(std::string tb_name, std::shared_ptr<Data> data, std::shared_ptr<Data> new_data);
    std::vector<std::shared_ptr<Data>> selectInTable(std::string tb_name, const Filter& filter, size_t from_index, 
                                              size_t to_index, bool sorted, 
                                              std::string column_name_to_sort_by) const;
    ~Database();
};
