class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>> keyStore;
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        keyStore[key].emplace_back(timestamp,value);
    }
    
    string get(string key, int timestamp) {
        auto& values = keyStore[key];
        int left = 0, right = values.size();

        while(left < right) {
            int mid = (right-left)/2 + left;

            if(values[mid].first > timestamp) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left > 0 ? values[left-1].second : "";
    }
};
