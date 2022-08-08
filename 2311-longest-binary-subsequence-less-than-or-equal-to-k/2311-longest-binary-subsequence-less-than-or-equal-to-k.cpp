class Solution {
public:
    int longestSubsequence(string s, int k) {
        reverse(s.begin(), s.end());
        int ans=0;
        for (int i=0; i<s.size(); ++i) {
            if (s[i]=='0')
                ans++;
            else if (i<30 and k>=(1<<i)) {
                    ans++;
                    k-=(1<<i);
                }
            }
        return ans;
    }
};