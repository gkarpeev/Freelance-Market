#pragma once

#include <iostream>
#include <vector>

class LogLevel {
public:
    enum Value {
        INFO,
        ERROR,
        WARNING,
        DEBUG
    };

    LogLevel() = default;
    LogLevel(Value log_level);

    bool operator==(const LogLevel& other) const;

    size_t getValue() const;
    
    std::vector<LogLevel> all();

private:
    Value value_;
};

std::ostream& operator<<(std::ostream& out, const LogLevel& level);


namespace std {

template <>
struct hash<LogLevel> {
    size_t operator()(const LogLevel& log_level) const {
    return log_level.getValue();
    }
};

}
