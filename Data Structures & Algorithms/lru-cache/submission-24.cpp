class LRUCache {
    unordered_map<int, pair<int, list<int>::iterator>> cache;
    int capacity;
    list<int> keys;

   public:
    LRUCache(int capacity) { this->capacity = capacity; }

    int get(int key) {
        if (cache.count(key)) {
            keys.erase(cache[key].second);
            keys.push_back(key);
            cache[key].second = --keys.end();
            return cache[key].first;
        }
        return -1;
    }

    void put(int key, int value) {
        if (capacity == 0) {
            return;
        }
        if (cache.count(key)) {
            keys.erase(cache[key].second);
        } else if (cache.size() == capacity) {
            int lru = keys.front();
            keys.pop_front();
            cache.erase(lru);
        }
        keys.push_back(key);
        cache[key] = {value, --keys.end()};
    }
};
