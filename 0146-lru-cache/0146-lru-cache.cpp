#include <unordered_map>
#include <list>
using namespace std;

class LRUCache {
    int cap;
    // front = most recently used, back = least recently used
    list<pair<int,int>> dll; // {key, value}
    unordered_map<int, list<pair<int,int>>::iterator> mp; // key -> iterator in dll

public:
    LRUCache(int capacity) : cap(capacity) {}

    int get(int key) {
        auto it = mp.find(key);
        if (it == mp.end()) return -1;

        // move accessed node to front (MRU)
        dll.splice(dll.begin(), dll, it->second);
        return it->second->second; // value
    }

    void put(int key, int value) {
        auto it = mp.find(key);

        if (it != mp.end()) {
            // update value + move to front
            it->second->second = value;
            dll.splice(dll.begin(), dll, it->second);
            return;
        }

        // evict if full
        if ((int)mp.size() == cap) {
            int lruKey = dll.back().first;
            mp.erase(lruKey);
            dll.pop_back();
        }

        // insert new at front
        dll.emplace_front(key, value);
        mp[key] = dll.begin();
    }
};