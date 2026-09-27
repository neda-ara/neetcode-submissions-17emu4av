class TimeMap {
    unordered_map<string,vector<pair<int,string>>> keyStore;

public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        keyStore[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if(keyStore.find(key) == keyStore.end()) {
            return "";
        }

        auto& values = keyStore[key];
        int l = 0, r = keyStore[key].size() - 1;
        string res;

        while(l <= r) {
            int m = l + (r-l)/2;

            if(values[m].first <= timestamp) {
                res = values[m].second;
                l = m+1;
            } else {
                r = m - 1;
            }
        }

        return res;
    }
};
