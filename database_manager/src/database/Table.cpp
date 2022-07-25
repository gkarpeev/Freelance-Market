#include "Table.h"
#include <algorithm>

// 
// CLASS TABLE STARTS
//

Table::Table(std::string tb_name, DataType columns_types) : types_of_columns_(std::make_shared<DataType>(columns_types)), tb_name_(tb_name) {} 

// TODO: make error handling
void Table::addColumn(std::string column_name, std::string column_type, std::string column_value) {
    types_of_columns_->addColumn(column_name, column_value);
    for (auto& element : data_) {
        element->addColumn(column_name, column_value);
    }
}

void Table::removeColumn(std::string column_name) {
    types_of_columns_->removeColumn(column_name);
    for (auto& element : data_) {
        element->removeColumn(column_name);
    }
}

std::vector<std::shared_ptr<Data>>::const_iterator Table::findData(std::shared_ptr<Data> data) const {
    for (auto it = data_.cbegin(); it != data_.cend(); ++it) {
        if (*(*it) == *data) {
            return it;
        }
    }
    return data_.cend();
}

void Table::insertData(std::shared_ptr<Data> data) {
    auto it = findData(data);
    if (it != data_.cend()) return;
    data_.push_back(data);
}

void Table::eraseData(std::shared_ptr<Data> data) {
    auto it = findData(data);
    if (it == data_.cend()) return;
    data_.erase(it);
}

void Table::updateData(std::shared_ptr<Data> data, std::shared_ptr<Data> new_data) {
    eraseData(data);
    insertData(new_data);
}

std::vector<std::shared_ptr<Data>> Table::select(const Filter& filter, size_t from_index, 
                                                 size_t to_index, bool sorted = false, 
                                                 std::string column_name_to_sort_by = "") const {
    if (!types_of_columns_->columnExist(column_name_to_sort_by)) {
        // ERROR
        return {};
    }
    std::vector<std::shared_ptr<Data>> result;
    if (sorted) {
        std::vector<std::pair<std::string, std::shared_ptr<Data>>> matched;
        for (auto& element : data_) {
            if (filter.matchesFilter(element)) {
                matched.push_back({element->getColumnValue(column_name_to_sort_by), element});
            }
        }

        auto column_type = types_of_columns_->getColumnType(column_name_to_sort_by);
        
        if (column_type == "string") {
            auto compare = [&](const std::pair<std::string, std::shared_ptr<Data>> &a, 
                               const std::pair<std::string, std::shared_ptr<Data>> &b) {
                if (a.first != b.first) return a.first < b.first;
                return a.second < b.second;
            };
            std::sort(matched.begin(), matched.end(), compare);

        } else if (column_type == "int") {
            auto compare = [&](const std::pair<std::string, std::shared_ptr<Data>> &a, 
                               const std::pair<std::string, std::shared_ptr<Data>> &b) {
                if (a.first != b.first) return stoi(a.first) < stoi(b.first);
                return a.second < b.second;
            };
            std::sort(matched.begin(), matched.end(), compare);

        } else if (column_type == "double") {
            const double eps = 1e-5;
            auto compare = [&](const std::pair<std::string, std::shared_ptr<Data>> &a, 
                               const std::pair<std::string, std::shared_ptr<Data>> &b) {
                if (!(std::abs(stod(a.first) - stod(b.first)) < eps)) return stod(a.first) < stod(b.first);
                return a.second < b.second;
            };
            std::sort(matched.begin(), matched.end(), compare);
        }

        for (size_t i = from_index; i <= to_index && i < matched.size(); i++) {
            result.push_back(matched[i].second);
        }
    } else {
        int cnt = 0;
        for (auto& element : data_) {
            if (filter.matchesFilter(element)) {
                cnt++;
                if (to_index <= cnt && cnt <= from_index) {
                    result.push_back(element);
                }
            } 
        }
    }
    return result;
}

std::string Table::getTableName() const {
    return tb_name_;
}

// 
// CLASS TABLE ENDS
//