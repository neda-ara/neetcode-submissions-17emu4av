class TimeMap {
public:
    unordered_map<string,map<int,string>> keyStore;
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        keyStore[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if(!keyStore.count(key)) {
            return "";
        }

        auto& timeMap = keyStore[key];

        auto it = timeMap.lower_bound(timestamp);

        if(it != timeMap.end() && it->first == timestamp) {
            return it->second;
        }

        return it == timeMap.begin() ? "" : prev(it)->second;
    }
};
