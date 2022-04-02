class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int>res;
        vector<int> freq(1001,0);
        for(int num:nums1)
            freq[num]++;
        for(int num:nums2)
            if(freq[num]>0)
            {
                freq[num]--;
                res.push_back(num);
            }
        
        return res;
    }
};