class Node {
   public:
    int key;
    int val;
    Node* prev;
    Node* next;

    Node(int k, int v, Node* next = nullptr, Node* prev = nullptr)
        : key(k), val(v), next(next), prev(prev) {};
};

class LRUCache {
   public:
    int capacity;
    Node* left;
    Node* right;
    unordered_map<int,Node*> cache;

    LRUCache(int capacity) {
        this->capacity = capacity;
        left = new Node(0,0);
        right = new Node(0,0);
        left->next = right;
        right->prev = left;
    }

    ~LRUCache() {
        Node* curr = left;
        while (curr) {
            Node* nxt = curr->next;
            delete curr;
            curr = nxt;
        }
    }

    int get(int key) {
        if(cache.count(key)) {
            Node* existing = cache[key];
            remove(existing);
            insert(existing);
            return existing->val;
        }
        return -1;
    }

    void put(int key, int value) {
        if(cache.count(key)) {
            Node* existing = cache[key];
            existing->val = value;
            remove(existing);
            insert(existing);
            return;
        }
        if(capacity == cache.size()) {
            Node* lru = left->next;
            cache.erase(lru->key);
            remove(lru);
            delete lru;
        }
        Node* node = new Node(key,value);
        insert(node);
        cache[key] = node;
    }

private:
    void insert(Node* node) {
        Node* last = right->prev;
        last->next = node;
        node->prev = last;
        node->next = right;
        right->prev = node;
    }

    void remove(Node* node) {
        Node* prev = node->prev;
        Node* next = node->next;

        if(prev) {
            prev->next = next;
        }
        if(next) {
            next->prev = prev;
        }
    }
};
