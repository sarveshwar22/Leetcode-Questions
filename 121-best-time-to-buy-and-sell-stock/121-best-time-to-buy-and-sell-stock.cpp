class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res=0;
        int price=prices[0];
        for(int i=1;i<prices.size();i++)
        {
            res=max(res,prices[i]-price);
            price=(price>prices[i])?prices[i]:price;
        }
        return res;
    }
};