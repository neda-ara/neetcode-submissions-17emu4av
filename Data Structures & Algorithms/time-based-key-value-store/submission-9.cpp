class TimeMap {
    unordered_map<string,unordered_map<int,string>> keyStore;

public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        keyStore[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        int time_max = -1;
        string res;

        if(keyStore.count(key)) {
            for(auto& [time,val] : keyStore[key]) {
                if(time <= timestamp) {
                    time_max = max(time_max,time);
                }
            }
        }

        return time_max == -1 ? "" : keyStore[key][time_max];
    }
};
