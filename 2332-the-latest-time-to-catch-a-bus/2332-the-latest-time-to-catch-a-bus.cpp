class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
        sort(buses.begin(),buses.end());
        sort(passengers.begin(),passengers.end());
        
        unordered_map<int,int> m;
        int j=0;
        int ans=-1;
        
        for(int i=0;i<buses.size();i++)
        {
            int curr =0 ;
            while(curr<capacity && j<passengers.size() && passengers[j]<=buses[i])
            {
                if(!m.count(passengers[j]-1))
                {
                    ans = passengers[j]-1;
                    
                }
                m[passengers[j]]++;
                j++;
                curr++;
                
            }
            if(curr<capacity && !m.count(buses[i]))
                ans  = buses[i];
        }
        return ans;
    }
};