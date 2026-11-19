class TimeMap {
    unordered_map<string, vector<pair<int,string>>> store;

public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        store[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(!store.count(key)) {
            return "";
        }

        auto& values = store[key];
        int l = 0, r = values.size();

        while(l < r) {
            int mid = l + (r-l)/2;
            int midTime = values[mid].first;

            if(midTime <= timestamp) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }

        return l > 0 ? values[l-1].second : "";
    }
};
