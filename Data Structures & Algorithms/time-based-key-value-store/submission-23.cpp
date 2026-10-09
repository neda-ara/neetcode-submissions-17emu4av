class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>> keyStore;
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        keyStore[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if(!keyStore.count(key)) {
            return "";
        }

        auto& values = keyStore[key];

        int l = 0, r = values.size();

        while(l < r) {
            int m = l + (r-l)/2;
            int midTime = values[m].first;

            if(midTime <= timestamp) {
                l = m+1;
            } else {
                r = m;
            }
        }

        return l > 0 ? values[l-1].second : "";
    }
};
