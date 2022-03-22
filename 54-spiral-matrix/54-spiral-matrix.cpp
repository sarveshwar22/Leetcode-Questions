class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        int m=matrix.size();
        if(m==0)
            return vector<int>();
        int n=matrix[0].size();
        int up=0;
        int down=m-1;
        int left=0;
        int right=n-1;
        int p=0;
        vector<int>res(m*n);
        
        while(up<=down && left<=right)
        {
            for(int col=left;col<=right;col++)
            {
                res[p++]=matrix[up][col];
            }
            
            if(++up>down)
                break;
            
            for(int row=up;row<=down;row++)
            {
                res[p++]=matrix[row][right];
            }
            
            if(--right<left)
                break;
            
            for(int col=right;col>=left;col--)
            {
                res[p++]=matrix[down][col];
            }
            
            if(--down<up)
                break;
            
            for(int row=down;row>=up;row--)
            {
                res[p++]=matrix[row][left];
            }
            
            if(left++>right)
                break;
        }
        return res;
    }
};