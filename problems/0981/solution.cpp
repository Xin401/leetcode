#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class TimeMap {
  unordered_map<string, vector<pair<int, string>>> map;

 public:
  TimeMap() {}

  void set(string key, string value, int timestamp) {
    map[key].push_back({timestamp, value});
  }

  string get(string key, int timestamp) {
    auto it = map.find(key);
    if (it == map.end()) {
      return "";
    }
    auto& tmp = it->second;
    int left = 0;
    int right = tmp.size() - 1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (tmp[mid].first == timestamp) {
        return tmp[mid].second;
      } else if (tmp[mid].first < timestamp) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    if (right < 0) {
      return "";
    }
    return tmp[right].second;
  }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */