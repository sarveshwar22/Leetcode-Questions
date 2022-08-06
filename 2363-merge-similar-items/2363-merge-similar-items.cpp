class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        vector<vector<int>> res;
        map<int,int> m;
        for(auto& ele:items1)
            m[ele[0]]+=ele[1];
        
        for(auto& ele:items2)
            m[ele[0]]+=ele[1];
        
        for(auto ele:m)
            res.push_back({ele.first,ele.second});
        return res;
    }
};