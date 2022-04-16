class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(),wordList.end());
        unordered_set<string> visited;
        vector<vector<string>> res;
        queue<vector<string>> q;
        int k=beginWord.size();
        q.push({beginWord});
        
        while(!q.empty())
        {
            int n=q.size();
            while(n--)
            {
                vector<string> currPath = q.front();
                q.pop();
                for(int i=0;i<k;i++)
                {
                    string temp=currPath.back();
                    for(char ch='a';ch<='z';ch++)
                    {
                        temp[i]=ch;
                        if(dict.find(temp)!=dict.end())
                        {
                            vector<string> newPath=currPath;
                            newPath.push_back(temp);
                            visited.insert(temp);
                            if(temp==endWord)
                                res.push_back(newPath);
                            else
                                q.push(newPath);
                        }
                    }
                }
            }
            for(auto& str: visited)
                dict.erase(str);
        }
        return res;
    }
};