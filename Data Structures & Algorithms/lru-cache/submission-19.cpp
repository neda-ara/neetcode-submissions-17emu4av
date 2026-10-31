class Node {
public:
    int key;
    int val;
    Node* next;
    Node* prev;
    Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {};
};

class LRUCache {
    int cap;
    Node* left;
    Node* right;
    unordered_map<int,Node*> cache;
public:
    LRUCache(int capacity) {
        cap = capacity;
        left = new Node(0,0);
        right = new Node(0,0);
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
    
    int get(int key) {
        if(cache.count(key)) {
            Node* node = cache[key];
            remove(node);
            insert(node);
            return node->val;
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
        if(cache.size() == cap) {
            Node* lru = left->next;
            cache.erase(lru->key);
            remove(lru);
            delete lru;
        }
        Node* newNode = new Node(key,value);
        cache[key] = newNode;
        insert(newNode);
    }

    void insert(Node* node) {
        if(!node) {
            return;
        }
        Node* last = right->prev;
        last->next = node;
        node->prev = last;
        node->next = right;
        right->prev = node;
    }

    void remove(Node* node) {
        if(!node) {
            return;
        }
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
