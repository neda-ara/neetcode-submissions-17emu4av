class TimeMap {
    unordered_map<string, unordered_map<int, string>> store;

   public:
    TimeMap() {}

    void set(string key, string value, int timestamp) { store[key][timestamp] = value; }

    string get(string key, int timestamp) {
        if (!store.count(key)) {
            return "";
        }

        int time = -1;

        for (auto& [t, _] : store[key]) {
            if(t <= timestamp) {
                time = max(time, t);
            }
        }

        return time == -1 ? "" : store[key][time];
    }
};
