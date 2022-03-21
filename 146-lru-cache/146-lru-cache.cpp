class LRUCache {
private:
    int size;
    list<int> recent;
    unordered_map<int, int> m;
    unordered_map<int, list<int>::iterator> pos;
    void used(int key) {
        if (pos.find(key) != pos.end()) {
            recent.erase(pos[key]);
        } else if (recent.size() >= size) {
            int old = recent.back();
            recent.pop_back();
            m.erase(old);
            pos.erase(old);
        }
        recent.push_front(key);
        pos[key] = recent.begin();
    }
public:
    LRUCache(int capacity) {
        size=capacity;
    }
    int get(int key) {
        if (m.find(key) != m.end()) {
            used(key);
            return m[key];
        }
        return -1;
    }
    void put(int key, int value) {
        used(key);
        m[key] = value;
    }
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */