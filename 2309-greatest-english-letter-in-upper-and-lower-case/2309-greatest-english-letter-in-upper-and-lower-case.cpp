class Solution {
public:
    string greatestLetter(string s) {
        vector<int> m1(26,0);
        vector<int> m2(26,0);
        for(char ch:s)
        {
            if(ch>='a' && ch<='z')
                m1[ch-'a']++;
            else
                m2[ch-'A']++;
        }
        string ans="";
        for(int i=0;i<26;i++)
        {
            if(m1[i]>0 && m2[i]>0)
                ans='A'+i;
        }
        return ans;
    }
};