class LRUCache {
private:
    vector<pair<int,int>> cache;
    int capacity;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        for(int i=0; i<cache.size(); i++) {
            if(key == cache[i].first) {
                pair<int,int> tmp = cache[i];
                cache.erase(cache.begin()+i);
                cache.push_back(tmp);
                return tmp.second;
            }
        }
        return -1;
    }
    
    void put(int key, int value) {
        for(int i=0; i<cache.size(); i++) {
            if(key == cache[i].first) {
                cache.erase(cache.begin()+i);
            }
        }
        if(capacity == cache.size()) {
            cache.erase(cache.begin());
        }
        cache.push_back({key,value});
        return;
    }
};
