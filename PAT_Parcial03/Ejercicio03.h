#include <string>
#include <map>

class TimeMap {
public:
    TimeMap();
    void set(std::string key, std::string value, int timestamp);
    std::string get(std::string key, int timestamp);

private:
    std::map<std::string, std::map<int, std::string>> data;
};
