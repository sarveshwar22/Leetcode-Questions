class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int> cnt, m;
        for(int num:nums)
            cnt[num]++;
        for(int num:nums)
        {
            if(!cnt[num])
                continue;
            cnt[num]--;
            if(m[num-1]>0)
            {
                m[num-1]--;
                m[num]++;
                
            }
            else if(cnt[num+1] && cnt[num+2])
            {
                cnt[num+1]--;
                cnt[num+2]--;
                m[num+2]++;
            }
            else return false;
        }
        return true;
    }
};