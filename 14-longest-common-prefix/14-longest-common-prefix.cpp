class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string pre=strs[0];
        for(int i=1;i<strs.size();i++)
        {
            int j=0;
            while(j<strs[i].size())
            {
                if(pre[j]==strs[i][j])
                    j++;
                else break;
            }
            pre.erase(pre.begin()+j,pre.end());
        }
        return pre;
    }
};