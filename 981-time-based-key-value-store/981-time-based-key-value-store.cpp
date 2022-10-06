class TimeMap {
    unordered_map<string,vector<pair<int,string>>> m;
public:
    TimeMap() {
        m.clear();
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        auto it=upper_bound(m[key].begin(),m[key].end(),pair<int,string>(timestamp,""),
                           [](const pair<int,string>& p1,const pair<int,string>& p2)
                            {
                                return p1.first<p2.first;
                            });
        return it==m[key].begin()?"":prev(it)->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */