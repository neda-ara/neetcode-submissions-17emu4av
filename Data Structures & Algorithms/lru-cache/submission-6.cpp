class Node {
public: 
    int key;
    int value;
    Node* prev;
    Node* next;

    // Member initializer list
    Node(int k, int v): key(k), value(v), prev(nullptr), next(nullptr) {};
};

class LRUCache {
private:
    unordered_map<int,Node*> cache;
    Node* left;
    Node* right;
    int capacity;

    void remove(Node* node) {
        Node* prev = node -> prev;
        Node* next = node -> next;
        prev -> next = next;
        next -> prev = prev;
    }

    void insert(Node* node) {
        Node* prev = right -> prev;
        prev -> next = node;
        node -> prev = prev;
        node -> next = right;
        right -> prev = node;
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        left = new Node(0,0);
        right = new Node(0,0);
        left -> next = right;
        right -> prev = left;
    }
    
    int get(int key) {
        if(cache.find(key) != cache.end()) {
            Node* node = cache[key];
            remove(node);
            insert(node);
            return node->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end()) {
            Node* node = cache[key];
            node -> value = value;
            remove(node);
            insert(node);
            return;
        }
        
        Node* newNode = new Node(key,value);
        cache[key] = newNode;
        insert(newNode);
        
        if(capacity < cache.size()) {
            Node* lru = left -> next;
            remove(lru);
            cache.erase(lru->key);
            delete lru;
        }
    }
};
