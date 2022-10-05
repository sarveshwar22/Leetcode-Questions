typedef long long int ll;
const int MOD = 1e9+7;
const ll P = 37;

class Solution {
    vector<int> dp;
    vector<vector<ll>> hashes;
    
    void PreComputeHash (const string& s) {
        int n = s.length();
        hashes.clear();
        hashes.resize(n);
        
        for (int j = 0; j < n; j ++) {
            ll pwr = P;
            ll prefix = 0;
            vector<ll>& start_j_hash = hashes[j]; 
            
            for (int k = j; k < n; k ++) {
                ll val = (pwr * s[k]) % MOD;
                prefix = (prefix + val) % MOD;
                
                start_j_hash.push_back (prefix);
                pwr = (pwr * P) % MOD;
            }
        }
    }
    
    bool IsEqual (int l1, int r1, int l2, int r2) {
        int len = (r2 - l2 + 1);
        
        return (hashes[l1][len-1] == hashes[l2][len-1]);
    }
    
    int MaxOperation (int ind, const int len) {
        if (ind == len) return 0;
        if (dp[ind] != -1) return dp[ind];
        
        int& ans = dp[ind];
        ans = 1;    // delete the entire string.
        
        for (int j = 1; j < len; j ++) {
            int l1 = ind, r1 = l1 + j - 1;
            int l2 = r1 + 1, r2 = l2 + j - 1;
            
            if (r1 >= len || r2 >= len) break;
            
            if (IsEqual(l1, r1, l2, r2)) ans = max (ans, 1+MaxOperation (r1+1, len));
        }
        return ans;
    }
    
public:
    int deleteString(string s) {
        int n = s.length();
        dp.clear();
        dp.resize(n, -1);
        
        PreComputeHash(s);
        
        return MaxOperation (0, n);
    }
};