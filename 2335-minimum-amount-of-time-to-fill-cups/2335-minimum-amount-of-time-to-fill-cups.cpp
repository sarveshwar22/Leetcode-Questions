class Solution {
public:
    int fillCups(vector<int>& amount) {
        int sum = accumulate(amount.begin(),amount.end(),0);
        int maxi = *max_element(amount.begin(),amount.end());
        return max((sum+1)/2,maxi);
    }
};