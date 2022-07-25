#include "Database.h"

// 
// CLASS DATABASE STARTS
//

Database::Database() {}

Database* Database::database_ = nullptr;

Database* Database::getInstance(const std::string& db_name) {
    if (database_ == nullptr) {
        database_ = new Database;
        database_->db_name_ = db_name;
    }
    return database_;
}

std::shared_ptr<Table> Database::getTable(const std::string& tb_name) const {
    auto it = tables_.find(tb_name);
    if (it != tables_.end()) {
        return it->second;
    }
    return nullptr;
}

std::string Database::getDatabaseName() const {
    return db_name_;
}

// todo: make error handling
void Database::createTable(const std::string& tb_name, const DataType& columns_types) {
    if (tables_.find(tb_name) != tables_.end()) {
        return;
    }
    tables_[tb_name] = std::make_shared<Table> (tb_name, columns_types);
}

std::unordered_map<std::string, std::shared_ptr<Table>>::const_iterator Database::findTable(const std::string& tb_name) const {
    return tables_.find(tb_name);
}

bool Database::tableExist(const std::string& tb_name) const {
    return findTable(tb_name) != tables_.end();
}

void Database::addColumnToTable(std::string tb_name, std::string column_name, std::string column_type, std::string column_value) {
    if (!tableExist(tb_name)) return;
    (*findTable(tb_name)).second->addColumn(column_name, column_type, column_value);
}

void Database::removeColumnFromTable(std::string tb_name, std::string column_name) {
    if (!tableExist(tb_name)) return;
    (*findTable(tb_name)).second->removeColumn(column_name);
}

std::vector<std::shared_ptr<Data>>::const_iterator Database::findDataInTable(std::string tb_name, std::shared_ptr<Data> data) const {
    return (*findTable(tb_name)).second->findData(data);
} 

void Database::insertDataInTable(std::string tb_name, std::shared_ptr<Data> data) {
    if (!tableExist(tb_name)) return;
    (*findTable(tb_name)).second->insertData(data);
}

void Database::eraseDataInTable(std::string tb_name, std::shared_ptr<Data> data) {
    if (!tableExist(tb_name)) return;
    (*findTable(tb_name)).second->eraseData(data);
}

void Database::updateDataInTable(std::string tb_name, std::shared_ptr<Data> data, std::shared_ptr<Data> new_data) {
    if (!tableExist(tb_name)) return;
    (*findTable(tb_name)).second->updateData(data, new_data);
}

std::vector<std::shared_ptr<Data>> Database::selectInTable(std::string tb_name, const Filter& filter, size_t from_index, 
                                              size_t to_index, bool sorted, 
                                              std::string column_name_to_sort_by) const {
    if (!tableExist(tb_name)) return {};
    return (*findTable(tb_name)).second->select(filter, from_index, to_index, sorted, column_name_to_sort_by); 
}

// 
// CLASS DATABASE ENDS
//
