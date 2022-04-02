class Solution {
    vector<int> getRow(int rowIndex) {
        vector<vector<int>>ans;
        ans.push_back(vector<int>(1,1));
        if(rowIndex==0)
            return vector<int>(1,1);
        for(int i=1;i<=rowIndex;i++)
        {
            vector<int> curr;
            curr.push_back(1);
            for(int j=1;j<i;j++)
            {
                curr.push_back((ans[i-1][j-1]%10+ans[i-1][j]%10)%10);
            }
            curr.push_back(1);
            ans.push_back(curr);
        }
        return ans[rowIndex];
    }
public:
    int triangularSum(vector<int>& nums) {
        int n=nums.size();
        vector<int>mul=getRow(n-1);
        int res=0;
        for(int i=0;i<n;i++)
        {
            res+=mul[i]*nums[i];
            res%=10;
        }
        return res;
    }
};