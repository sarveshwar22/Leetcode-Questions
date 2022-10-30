class Solution {
public:
    string oddString(vector<string>& words) {
        map<vector<int>,int> m1;
        map<vector<int>,string> m2;
        for(string word:words)
        {
            vector<int> diff1;
            int n=word.size();
            for(int i=0;i<n-1;i++)
            {
                diff1.push_back(word[i+1]-word[i]);
            }
            m1[diff1]++;
            m2[diff1] = word;
        }
        for(auto& ele:m1)
        {
            if(ele.second==1)
                return m2[ele.first];
        }
        return "";
    }
};