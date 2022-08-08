class Solution {
public:
    int countAsterisks(string s) {
        int ans=0;
        bool flag=true;
        for(char ch:s)
        {
            if(flag && ch=='*')
                ans++;
            if(ch=='|')
                flag=!flag;
        }
        return ans;
    }
};