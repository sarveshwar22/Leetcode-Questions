class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        bool f1 = false;
        bool f2 = false;
        for(int i=0; i<nums.size()-1; i++){
            if(f1 && nums[i]>nums[i+1])
                return false;
            if(nums[i]>nums[i+1])
                f1 = true;
            
            if(i-1>=0 && i+1<nums.size()){
                if(f2 && nums[i+1]<nums[i-1])
                    return false;
                if(nums[i+1]<nums[i-1])
                    f2 = true;
            }
        }
        return true;
    }
};