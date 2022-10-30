class Solution {
public:
    int averageValue(vector<int>& nums) {
        int sum = 0, count = 0;
        for(auto n: nums){
            if(n%3 == 0 && n%2 == 0){
                sum += n;
                count++;
            }
        }
        return count != 0 ? sum/count: 0;
    }
};