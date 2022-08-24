class Solution {
public:
    string largestPalindromic(string num) {
        vector<int> m(10,0);
        for(char c:num)
        {
            m[c-'0']++;
        }
        string res1,res2;
        for(int i=9;i>=0;i--)
        {
            if(m[i]>1 && (i>=1 || res1.size()>0))
            {
                res1+=string(m[i]/2,'0'+i);
                res2+=string(m[i]/2,'0'+i);
                m[i]=m[i]%2;
            }
        }
        for(int i=9;i>=0;i--)
        {
            if(m[i]){
                res1.push_back('0'+i);break;
            }
        }
        reverse(res2.begin(),res2.end());
        return res1+res2;
    }
};