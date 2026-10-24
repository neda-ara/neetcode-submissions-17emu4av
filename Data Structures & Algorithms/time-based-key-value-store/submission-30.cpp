class TimeMap {
    unordered_map<string,unordered_map<int,string>> keyStore;
public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        keyStore[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if(!keyStore.count(key)) {
            return "";
        }

        int t = -1;
        for(const auto& [time,_] : keyStore[key]) {
            if(time <= timestamp) {
                t = max(t,time);
            }
        }

        return t == -1 ? "" : keyStore[key][t];
    }
};
