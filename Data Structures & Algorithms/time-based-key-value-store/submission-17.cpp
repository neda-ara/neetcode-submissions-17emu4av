class TimeMap {
    unordered_map<string,vector<pair<int,string>>> keyStore;
public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        keyStore[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if(!keyStore.count(key)) {
            return "";
        }
        
        auto& timeMap = keyStore[key];
        int l = 0, r = timeMap.size();

        while(l < r) {
            int mid = l + (r-l)/2; // --> (l+r)/2

            int midTime = timeMap[mid].first;
            if(midTime <= timestamp) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }

        return l == 0 ? "" : timeMap[--l].second;
    }
};
