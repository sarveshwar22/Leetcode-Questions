class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int m=matrix[0].size();
        for(int row=0;row<n;row++)
        {
            int currSum=0;
            for(int col=0;col<m;col++)
            {
                currSum+=matrix[row][col];
                matrix[row][col] = currSum;
            }
        }
        int res=INT_MIN;
        
        for(int ColStart=0;ColStart<m;ColStart++)
        {
            for(int col=ColStart;col<m;col++)
            {
                set<int> s;
                int rowSum=0;
                s.insert(rowSum);
                for(int row=0;row<n;row++)
                {
                    int curr=matrix[row][col]-((ColStart==0)?0:matrix[row][ColStart-1]);
                    rowSum+=curr;
                    auto it = s.lower_bound(rowSum-k);
                    if(it!=s.end())
                    {
                        res=max(res,rowSum-(*it));
                    }
                    s.insert(rowSum);
                }
            }
        }
        return res;
    }
};