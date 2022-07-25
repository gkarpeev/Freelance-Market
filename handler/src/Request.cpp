#include "Request.h"
#include <iostream>

// 
// CLASS Request STARTS
//

Request::Request(const std::string& type, const std::unordered_map<std::string, std::string>& content) : type_(type), content_(content){}

Request& Request::operator=(const Request& other) {
    type_ = other.getType();
    content_ = other.getContent();
    return *this;
}

bool Request::keyIsSet(const std::string& key) const {
    return content_.find(key) != content_.end();
}

void Request::set(const std::string& key, const std::string& value) {
    content_[key] = value;
}

void Request::setType(const std::string& type) {
    type_ = type;
}    

std::unordered_map<std::string, std::string> Request::getContent() const {
    return content_;
}

std::string Request::getType() const {
    return type_;
}

std::string Request::get(const std::string& key) const {
    return content_.find(key)->second;
}

// 
// CLASS Request ENDS
//

std::ostream& operator<<(std::ostream& out, const Request& request) {
    if (!request.getType().empty()) {
        out << "Request:" << " " << "[" << request.getType() << "]" << std::endl;
    }
    for (auto& el : request.getContent()) {
        out << "[" << el.first << "]:" << " " << el.second << std::endl;
    }
    return out;
}
