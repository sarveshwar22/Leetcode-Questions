class Solution {
    bool validPalindrome(string s, int low, int high,int& k)
    {
        while(low<high)
        {
            if(s[low]==s[high])
            {
                low++;
                high--;
            }
            else
            {
                k--;
                if(k<0)
                    return false;
                return validPalindrome(s,low+1,high,k)||validPalindrome(s,low,high-1,k);
            }
        }
        return true;
    }
public:
    bool validPalindrome(string s) {
        int low=0;
        int high=s.size()-1;
        int k=1;
        return validPalindrome(s,low,high,k);
    }
};