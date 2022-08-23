class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int res=0;
        vector<bool> visited(201,false);
        for(int num:nums)
        {
            if(num>=2*diff)
                res+=visited[num-diff]&&visited[num-2*diff];
            visited[num]=true;
        }
        return res;
    }
};