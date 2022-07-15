class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {

        int n=nums.size();
        vector<pair<long long,long long>>v;
        for(int i=0;i<n;i++) 
        v.push_back({nums[i],i});
        sort(v.begin(),v.end());
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if((v[j].first-v[i].first)>t) 
                    break;
                if(abs(v[j].second-v[i].second)<=k) 
                    return true;
            }
        }
        return false;



    }
};


// 1,5,9,1,5,9 k=2 t=3
// 0 - []
// 1 - [1]
// 2 - [1,5]
// 3 - [5,9]
// 4 - [9,1]
// 5 - []

// -t<=nums[i]-nums[j]<=t
// -k<=i-j<=k