class SmallestInfiniteSet {
    int cur = 1;
    set<int> s;
    
public:
    SmallestInfiniteSet() {
        
    }
    
    int popSmallest() {
        if(!s.empty())
        {    
            int res = *s.begin();
            s.erase(s.begin());
            return res;
        }
        return cur++;
    }
    
    void addBack(int num) {
        if(num<cur)
            s.insert(num);
        
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */