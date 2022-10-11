class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        stack<int>s;
        int bar=INT_MAX;
        for(int num:nums)
        {
            if(num>bar)
                return true;
            
            while(!s.empty() && num<=s.top())
                s.pop();
            if(!s.empty())
                bar=min(bar,num);
            
            s.push(num);
        }
        return false;
    }
};