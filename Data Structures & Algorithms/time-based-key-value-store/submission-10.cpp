class TimeMap {
    unordered_map<string,map<int,string>> keyStore;

public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        keyStore[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if(keyStore.find(key) == keyStore.end()) {
            return "";
        }

        auto it = keyStore[key].upper_bound(timestamp);
        if(it == keyStore[key].begin()) {
            return "";
        }
        return prev(it)->second;
    }
};
