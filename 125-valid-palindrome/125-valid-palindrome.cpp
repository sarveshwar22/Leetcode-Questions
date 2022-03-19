class Solution {
public:
    bool isPalindrome(string s) {
        string str;
        int i=0;
        while(i<s.size())
        {
            if(isalpha(s[i])||isdigit(s[i]))
            {
                str.push_back(tolower(s[i]));
            }
            i++;
        }
        int flag=1;
        int start=0;
        int end=str.length()-1;
        while(start<end)
        {
            if(str[start++]!=str[end--])
                return false;
        }
        return true;
    }
};