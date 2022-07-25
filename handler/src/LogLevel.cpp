#include "LogLevel.h"
#include <unordered_map>

LogLevel::LogLevel(LogLevel::Value log_level): value_(log_level) {}

bool LogLevel::operator==(const LogLevel& other) const {
    return value_ == other.value_;
}

size_t LogLevel::getValue() const {
    return value_;
}

std::vector<LogLevel> LogLevel::all() {
    return {
        LogLevel::INFO,
        LogLevel::ERROR,
        LogLevel::DEBUG,
        LogLevel::WARNING
    };
}

std::ostream& operator<<(std::ostream& out, const LogLevel& level) {
    std::unordered_map<LogLevel, std::string> strings {
        {LogLevel::INFO, "INFO"},
        {LogLevel::DEBUG, "DEBUG"},
        {LogLevel::WARNING, "WARNING"},
        {LogLevel::ERROR, "ERROR"}
    };
    out << strings[level];
    return out;
}
