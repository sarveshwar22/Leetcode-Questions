class Solution {    
public:
    int validSubarraySize(vector<int>& nums, int threshold) {
        vector<int> stk;
        nums.push_back(0);
        for(int i = 0; i < nums.size(); i++) 
        {
            while(!stk.empty() && nums[i] < nums[stk.back()])
            {
                int val = nums[stk.back()]; 
                stk.pop_back();
                int j = stk.empty()? -1:stk.back();
                int dist = i - j - 1;
                if(val > threshold / dist)
                {
                    return dist;
                }
            }
            stk.push_back(i);
        }
        return -1;
    }
};