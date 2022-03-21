class Solution {
    vector<string> dict={"0","1","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.empty())
            return res;
        queue<string>q;
        q.push("");
        while(!q.empty())
        {
            string s=q.front();
            q.pop();
            if(s.length()==digits.length())
            {
                res.push_back(s);
            }
            else
            {
                string temp=dict[digits[s.size()]-'0'];
                for(auto i:temp)
                {
                    q.push(s+i);
                }
            }
        }
        return res;
    }
};