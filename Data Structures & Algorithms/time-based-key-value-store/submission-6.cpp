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
        const auto& timeMap = keyStore[key];
        auto it = timeMap.upper_bound(timestamp);

        if(it == timeMap.begin()) {
            return "";
        }
        --it;
        return it->second;
    }
};
