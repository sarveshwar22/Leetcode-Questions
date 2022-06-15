class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](const std::string& first, const std::string& second){return first.size() < second.size();});
        
        unordered_map<string,int> m;
        int res = 0;
        
        for(string word:words)
        {
            int longest =0;
            for(int i = 0;i<word.size();i++)
            {
                string sub = word.substr(0,i) + word.substr(i+1,word.length()+1);
                longest = max(longest,m[sub]+1);   
            }
            
            m[word] = longest;
            res = max(res,longest);
        }
        return res;
    }
};