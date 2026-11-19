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
        auto it = timeMap.upper_bound(timestamp);

        return it == timeMap.begin() ? "" : prev(it)->second;
    }
};
