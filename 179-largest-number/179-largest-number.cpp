#include<string>
class Solution {
    static bool cmp(int a,int b)
    {
        string aStr = to_string(a);
        string bStr = to_string(b);
        return aStr+bStr>bStr+aStr;
    }
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),cmp);
        string ans="";
        for(int q:nums)
            ans+=to_string(q);
        bool flag= true;
        for(char a:ans)
        {
            if(a!='0')
            {
                flag=false;
                break;
            }
        }
        if(flag)
            return "0";
        return ans;
    }
};