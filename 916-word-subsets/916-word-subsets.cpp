class Solution {
     vector<int> counter(string& word) {
        vector<int> count(26);
        for (char c : word) count[c - 'a']++;
        return count;
    }
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> count(26);
        vector<int> temp(26);
        for(string word:words2)
        {
            temp = counter(word);
            for(int i=0;i<26;i++)
            {
                count[i] = max(count[i],temp[i]);
            }
        }
        vector<string> res;
        for(string word:words1)
        {
            temp = counter(word);
            int i=0;
            for(i=0;i<26;i++)
            {
                if(temp[i]<count[i])
                    break;
            }
            if(i==26)
                res.push_back(word);
        }
        return res;
    }
};