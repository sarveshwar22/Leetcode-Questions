class NumberContainers {
    unordered_map<int,set<int>> numberIndex;
    unordered_map<int,int> IndexNumber;
public:
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        auto it = IndexNumber.find(index);
        if(it!=IndexNumber.end())
        {
            numberIndex[it->second].erase(index);
        }
        IndexNumber[index] = number;
        numberIndex[number].insert(index);
    }
    
    int find(int number) {
        auto it = numberIndex.find(number);
        if(it==numberIndex.end() || it->second.empty())
            return -1;
        return *numberIndex[number].begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */