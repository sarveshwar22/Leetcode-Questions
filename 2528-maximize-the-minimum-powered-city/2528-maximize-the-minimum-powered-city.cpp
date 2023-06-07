typedef long long int ll;

class Solution {
    
    bool IsPossible (ll min_power, const vector<ll>& powers_s, int k, int r, int n) {
        vector<ll> extra_power (n+1);
        
        for (int j = 0; j < n; j ++) {
            extra_power[j] += (j > 0? extra_power[j-1] : 0);
            
            ll cur_power = powers_s[j] + extra_power[j];
            ll required = max (0LL, min_power - cur_power);
            if (required == 0) continue;
            
            if (required > k) return false;
            k -= required;
            
            extra_power[j] += required;
            extra_power[min(n, j+2*r+1)] -= required;
        }
        
        return true;
    }
    
public:
    long long maxPower(vector<int>& stations, int range, int k) {
        int n = stations.size();
     
        vector<ll> powers_s(n+1);
        for (int j = 0; j < n; j ++) {
            powers_s[max(0, j-range)] += stations[j];
            powers_s[min(n, j+range+1)] -= stations[j];
        }
        for (int j = 1; j <= n; j ++) powers_s[j] += powers_s[j-1];
        
        ll l = 0, r = 1e11;
        while (l < r) {
            ll m = (l+r) >> 1;
            
            if (IsPossible (m+1, powers_s, k, range, n)) l = m+1;
            else r = m;
        }
        
        return l;
    }
};