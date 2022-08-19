class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> freq;
        for(int num:arr)
        {
            freq[num]++;
        }
        priority_queue<int> pq;
        for(auto [_,f]:freq)
        {
            pq.push(f);
            
        }
        int res=0;
        int cnt = 0;
        while(cnt*2<arr.size())
        {
            res++;
            cnt+=pq.top();
            pq.pop();
        }
        return res;
    }
};