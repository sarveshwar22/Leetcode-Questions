class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        int dp[target+1][m+1][n];
        //minstore[t][i][0] = min index among dp[t][i][*] if such exists, otherwise equals -1;
        //minstore[t][i][1] = second min index among dp[t][i][*] if such exists, otherwise equals -1;
        int min_store[target][m][2];
        for(int i = 0; i < n; ++i){
            dp[0][0][i] = 0;
            for(int j = 1; j < m+1; ++j ){
            dp[0][j][i] = -1;
            }
        }
        min_store[0][0][0] = 0;
        min_store[0][0][1] = 0;
        for(int i = 1; i < m; ++i){
            min_store[0][i][0] = -1;
        min_store[0][i][1] = -1;
        }
        
        
        //iterate through number of neighbourhoods
        for(int t = 1; t <= target; ++t){
            //cout << "t = " << t << endl;
            //iterate through using array [0,i)
            for(int i = 0; i <n; ++i){
                dp[t][t-1][i] = -1;
            }
            for(int i = t; i <= m+t-target; ++i){
                //cout << "i = " << i << endl;
                //iterate through colors
                int begin = 0, end = n, maybe_color = houses[i-1];
                int min_idx1 = -1, min_idx2 = -1;
                if(maybe_color != 0){
                    begin = maybe_color -1;
                    end = maybe_color;
                    for(int j = 0; j < n; ++j){
                        if(j != begin)dp[t][i][j] = -1;
                    }
                }
                for(int j = begin; j < end; ++j){
                    //cout << "j = " << j << endl;
                    int idx_of_min = min_store[t-1][i-1][0];
                    int cost_of_last = cost[i-1][j];
                    int min_with_different = -1;
                    if(idx_of_min != -1){
                        if(idx_of_min == j){
                            int smin_index = min_store[t-1][i-1][1];
                            min_with_different = (smin_index == -1) ?-1:(dp[t-1][i-1][smin_index] + cost_of_last);
                        }else {
                            min_with_different = dp[t-1][i-1][idx_of_min] + cost_of_last;
                        } 
                    }
                    //cout << "diff: "  << min_with_different << endl;
                    int smin_without_last = dp[t][i-1][j];
                    int min_with_same = (smin_without_last  == -1) ? -1 : (smin_without_last + cost_of_last);
                    int ans;
                    if(min_with_same == -1){
                        ans = min_with_different;
                    }else {
                        ans = (min_with_different == -1)? min_with_same : min(min_with_same, min_with_different);
                    }
                    //cout << "same: " << min_with_same << endl;
                    if(ans != -1){
                        if(min_idx1 == -1 || ans <= dp[t][i][min_idx1]){
                        min_idx2 = min_idx1;
                        min_idx1 = j;
                        }else if(min_idx2 == -1 || ans <= dp[t][i][min_idx2]){
                            min_idx2 = j;
                        }
                    }
                    dp[t][i][j] = ans;
                    //cout << "ans: " << ans << endl;
                }
                if(maybe_color != 0 && dp[t][i][maybe_color -1] != -1){
                    dp[t][i][maybe_color -1] -= cost[i-1][maybe_color-1];
                }
                if(t != target){
                min_store[t][i][0] = min_idx1;
                min_store[t][i][1] = min_idx2;
                }
            }
        }
        int mini = INT_MAX;
        for(int i = 0; i < n; ++i){
            int x = dp[target][m][i];
            if(x != -1)mini = min(mini, x);
        }
        return (mini == INT_MAX)? -1: mini;
    }
};