class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0;
        int right=0;
        int n=s.size();
        vector<int> m(128,0);
        int maxans=0;
        while(right<n)
        {
            m[s[right]-'\0']++;
            while (m[s[right]-'\0']>1)
            {
                m[s[left]-'\0']--;
                left++;
            }
            maxans=max(maxans,right-left+1);
            right++;
        }
        return maxans;
    }
};