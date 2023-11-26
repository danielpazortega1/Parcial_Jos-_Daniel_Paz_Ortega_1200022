#include "Ejercicio03.h"

TimeMap::TimeMap() {}

void TimeMap::set(std::string key, std::string value, int timestamp) {
    data[key][timestamp] = value;
}

std::string TimeMap::get(std::string key, int timestamp) {
    if (data.find(key) == data.end()) {
        return "";
    }

    auto& timeMap = data[key];
    auto it = timeMap.upper_bound(timestamp);

    if (it == timeMap.begin()) {
        return ""; 
    }

    --it;
    return it->second;
}