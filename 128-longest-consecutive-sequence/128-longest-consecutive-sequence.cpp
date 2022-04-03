class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,int> m;
        for(int num:nums)
            m[num]++;
        int res=0;
        int prev=INT_MAX-1;
        int curr=1;
        for(auto ele:m)
        {
            if(prev+1==ele.first)
                curr++;
            else 
                curr=1;
            res=max(res,curr);
            prev=ele.first;
        }
        return res;
    }
};