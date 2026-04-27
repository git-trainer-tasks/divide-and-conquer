#include "filter.h"

#include <string>

bool matchesLevel(const std::string& line, const std::string& level) {
    std::string expectedPrefix = "[" + level + "]";
    return line.find(expectedPrefix) == 0;
}
