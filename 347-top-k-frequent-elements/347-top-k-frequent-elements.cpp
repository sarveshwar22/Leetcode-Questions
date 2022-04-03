class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        if(k==n)
            return nums;
        unordered_map<int,int>freq;
        for(auto& num:nums)
            freq[num]++;
        // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        // for(auto& ele:freq)
        // {
        //     pq.push({ele.second,ele.first});
        //     if(pq.size()>k)
        //         pq.pop();
        // }
        // vector<int>res(k);
        // for(int i=0;i<k;i++)
        // {
        //     res[i]=pq.top().second;
        //     pq.pop();
        // }
        
        vector<int>res;
        vector<vector<int>> bucket(n+1);
        int maxi=INT_MIN;
        for(auto& ele:freq)
        {
            bucket[ele.second].push_back(ele.first);
            maxi=max(maxi,ele.second);
        }
        
        int curr=maxi;
        while(res.size()<k)
        {
            if(!bucket.empty())
            {
                res.insert(res.end(),bucket[curr].begin(),bucket[curr].end());
                curr--;
            }
        }
        return res;
    }
};