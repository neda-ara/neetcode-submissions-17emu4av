class TimeMap {
public:
    unordered_map<string,unordered_map<int,string>> keyStore;
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        keyStore[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if(!keyStore.count(key)) {
            return "";
        }

        int seenTime = -1;

        for(const auto& [time,_] : keyStore[key]) {
            if(time <= timestamp) {
                seenTime = max(seenTime,time);
            }
        }

        return seenTime == -1 ? "" : keyStore[key][seenTime];
    }
};
