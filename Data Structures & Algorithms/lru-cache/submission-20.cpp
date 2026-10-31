class LRUCache {
    int cap;
    unordered_map<int, pair<int, list<int>::iterator>> cache;
    list<int> order;

   public:
    LRUCache(int capacity) { cap = capacity; }

    int get(int key) {
        if (cache.count(key)) {
            order.erase(cache[key].second);
            order.push_back(key);
            cache[key].second = --order.end();
            return cache[key].first;
        }
        return -1;
    }

    void put(int key, int value) {
        if (cap == 0) {
            return;
        }

        if (cache.count(key)) {
            cache[key].first = value;
            order.erase(cache[key].second);
        } else if (cap == cache.size()) {
            int lru = order.front();
            order.pop_front();
            cache.erase(lru);
        }
        order.push_back(key);
        cache[key] = {value, --order.end()};
    }
};
