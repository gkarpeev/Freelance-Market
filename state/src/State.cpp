#include "State.h"
#include <iostream>
#include <unordered_map>

std::ostream& operator<<(std::ostream& out, const Direction& direction) {
    std::unordered_map<Direction, std::string> strings {
        {Direction::ENTRANCE_MENU, "ENTRANCE_MENU"},
        {Direction::MAIN_MENU, "MAIN_MENU"}
    };
    out << strings[direction];
    return out;
}
