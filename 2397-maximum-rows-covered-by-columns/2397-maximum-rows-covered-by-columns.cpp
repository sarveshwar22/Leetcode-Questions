class Solution {
private:
    int ans;
    int n,m;
    void helper(vector<vector<int>>& mat, vector<int> &chose, int c, int cols) {
        if(cols == 0)
        {
            int cntRows = calcRow(mat, chose);
            ans = max(ans, cntRows);
            return;
        }
        
        if(c >= m) 
        {
            return;
        }
        
        helper(mat, chose, c + 1, cols);
        
		
        chose[c] = 1; 
        helper(mat, chose, c + 1, cols - 1);
        chose[c] = 0;
    }
    
    int calcRow(vector<vector<int>>& mat, vector<int> &chose) {
        int cnt = 0;
        
        for(int i = 0; i < n; i++) {
            bool ok = true;
            for(int j = 0; j < m; j++) 
            {
                if(mat[i][j] == 1 && chose[j] == 0) 
                {
					ok = false;
					break;
				}
            }
            if(ok) 
                cnt++;
        }
        
        return cnt;
    }
    
public:
    int maximumRows(vector<vector<int>>& mat, int cols) {
        ans = 0;
        n = mat.size();
        m = mat[0].size();
        vector<int> chose(m, 0);
        helper(mat, chose, 0, cols);
        return ans;
    }
};