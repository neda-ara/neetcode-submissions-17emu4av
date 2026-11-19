class TimeMap {
    unordered_map<string, map<int, string>> store;

   public:
    TimeMap() {}

    void set(string key, string value, int timestamp) { store[key][timestamp] = value; }

    string get(string key, int timestamp) {
        if (!store.count(key)) {
            return "";
        }

        auto& timeMap = store[key];
        auto it = timeMap.lower_bound(timestamp);

        if(it != timeMap.end() && it->first == timestamp) {
            return it->second;
        }

        return it == timeMap.begin() ? "" : prev(it)->second;
    }
};
