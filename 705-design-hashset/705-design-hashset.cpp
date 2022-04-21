class MyHashSet {
        set<int> x;
public:
    MyHashSet() {
    }
    
    void add(int key) {
        x.insert(key);
        
    }
    
    void remove(int key) {
        x.erase(key);
        
    }
    
    bool contains(int key) {
        return x.find(key)!=x.end();
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */