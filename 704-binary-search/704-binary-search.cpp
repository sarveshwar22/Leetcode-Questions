class Solution {
public:
    int search(vector<int>& nums, int target) {
        return find(nums.begin(),nums.end(),target)!=nums.end()?find(nums.begin(),nums.end(),target)-nums.begin():-1;
    }
};