class TimeMap {
    unordered_map<string,map<int,string>> keyStore;

public:
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

        if(it == timeMap.begin()) {
            if(it->first == timestamp) {
                return it->second;
            } else {
                return "";
            }
        }

        return it != timeMap.end() && it->first == timestamp ? it->second : prev(it)->second;
    }
};
