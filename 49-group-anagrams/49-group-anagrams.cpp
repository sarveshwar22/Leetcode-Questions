class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>m;
        for(int i=0;i<strs.size();i++)
        {
            string temp=strs[i];
            sort(temp.begin(),temp.end());
            m[temp].push_back(strs[i]);
        }
        vector<vector<string>>ans;
        for(auto ele:m)
        {
            vector<string>temp;
            for(int i=0;i<ele.second.size();i++)
            {
                temp.push_back(ele.second[i]);
            }
            ans.push_back(temp);
        }
        return ans;
            
    }
};