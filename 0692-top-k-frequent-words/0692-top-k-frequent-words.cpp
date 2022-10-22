class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> m;
        for (string& word : words)
            m[word]++;
        vector<vector<string>> bucket(words.size());
        for (auto& it : m)
            bucket[it.second].push_back(it.first);
        
        vector<string> res;
        for (int i = (int)bucket.size() - 1;i >= 0; i--) {
            if(k<=0)
                break;
            int n = min(k,(int)bucket[i].size());
            res.insert(res.end(), bucket[i].begin(), bucket[i].begin() + n);
            k -= n;
        }
        
        return res;
    }
};