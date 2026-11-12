class Node {
   public:
    int key;
    int value;
    Node* prev;
    Node* next;

    Node(int k, int v, Node* prev = nullptr, Node* next = nullptr)
        : key(k), value(v), next(next), prev(prev) {};
};

class LRUCache {
    unordered_map<int, Node*> cache;
    int capacity;
    Node* left;
    Node* right;

   public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        left = new Node(0, 0);
        right = new Node(0, 0);
        
        left->next = right;
        right->prev = left;
    }

    ~LRUCache() {
        Node* curr = left;
        while(curr) {
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
    }

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

    int get(int key) {
        if(cache.count(key)) {
            Node* existing = cache[key];
            remove(existing);
            insert(existing);
            return existing->value;
        }
        return -1;
    }

    void put(int key, int value) {
        if (capacity == 0) {
            return;
        }
        if(cache.count(key)) {
            Node* existing = cache[key];
            existing->value = value;
            remove(existing);
            insert(existing);
            return;
        }
        if(cache.size() == capacity) {
            Node* lru = left->next;
            cache.erase(lru->key);
            remove(lru);
            delete lru;
        }
        Node* newNode = new Node(key, value);
        cache[key] = newNode;
        insert(newNode);
    }
};
