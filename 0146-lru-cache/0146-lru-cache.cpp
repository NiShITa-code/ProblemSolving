class LRUCache {
private:
    struct Node {
        int key, val;
        Node* next;
        Node* prev;
        Node(int k, int v) {
            key = k;
            val = v;
            prev = next = nullptr;
        }
    };

    int capacity;
    unordered_map<int, Node*>mp;
    Node* head;
    Node* tail;

    void remove(Node* node) {
        node -> prev -> next = node -> next;
        node -> next -> prev = node -> prev; 
    }

    void insert(Node* node) {
        node -> next = head -> next;
        node -> prev = head;
        head -> next -> prev = node;
        head -> next = node;
    }

public:
    LRUCache(int capacity) {
        this -> capacity = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head -> next = tail;
        tail -> prev = head;
    }
    
    int get(int key) {
        if (mp.find(key) == mp.end()){
            return -1;
        } 
        Node* node = mp[key];
        remove(node);
        insert(node);
        return node -> val;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()) {
            Node* node = mp[key];
            node->val = value;
            remove(node);
            insert(node);
        } 
        else {
            if(mp.size() == capacity) {
                Node* lru = tail->prev;
                mp.erase(lru->key);
                remove(lru);
            }

            Node* node = new Node(key, value);
            mp[key] = node;
            insert(node);
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */