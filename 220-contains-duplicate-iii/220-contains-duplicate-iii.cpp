class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {

        int n = nums.size();
        if(n==1 || k==0) return false; 
        set<int> st;  
        st.emplace(nums[0]);
        for(int i=1; i<n; i++){
            auto it = st.upper_bound(nums[i]);   
            if(it!=st.end()){
                if(abs((long long)*it - nums[i])<=t) return true;
            }
            if(it!=st.begin()){
                it--;   
                if(abs((long long)*it - nums[i])<=t) return true;
            }
            st.emplace(nums[i]);
            if(st.size()>k) st.erase(st.find(nums[i-k]));  
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