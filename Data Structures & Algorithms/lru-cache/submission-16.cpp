class Node {
public:
    int key;
    int val;
    Node* prev;
    Node* next;

    Node(int k, int v): key(k), val(v), prev(nullptr), next(nullptr) {};
};

class LRUCache {
    int capacity;
    Node* left;
    Node* right;
    unordered_map<int,Node*> cache;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        left = new Node(0,0);
        right = new Node(0,0);
        left->next = right;
        right->prev = left;
    }

    ~LRUCache() {
        Node* curr = left;
        while(curr) {
            Node* nxt = curr->next;
            delete curr;
            curr = nxt;
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
            Node* node = cache[key];
            node->val = value;
            remove(node);
            insert(node);
            return;
        }
        if(cache.size() == capacity) {
            Node* first = left->next;
            cache.erase(first->key);
            remove(first);
            delete first;
        }
        Node* newNode = new Node(key,value);
        cache[key] = newNode;
        insert(newNode);
    }

    void insert(Node* node) {
        Node* last = right->prev;
        last->next = node;
        node->next = right;
        node->prev = last;
        right->prev = node;
    }

    void remove(Node* node) {
        Node* prv = node->prev;
        Node* nxt = node->next;
        prv->next = nxt;
        nxt->prev = prv;
    }
};
