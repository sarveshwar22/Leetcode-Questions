class Solution {
    const int MOD=1e9+7;
    unordered_map<int,long long int>m;
public:
    int threeSumMulti(vector<int>& arr, int target) {
        
        sort(arr.begin(),arr.end());
        int n=arr.size();
        for(auto &i:arr)
            m[i]++;
        vector<vector<int>> res;
        for(int k=0;k<n;k++)
        {
            if(k>0 && arr[k]==arr[k-1])continue;
            int i=k+1,j=n-1;
            while(i<j){
                int sum=arr[i]+arr[j]+arr[k];
                if(sum==target){
                    res.push_back({arr[k],arr[i],arr[j]});
                    while(i<j && arr[i]==arr[i+1])i++;
                    while(i<j && arr[j]==arr[j-1])j--;
                    i++;j--;
                }
                else if(sum>target)j--;
                else i++;
        }
        }
            
        long long int ans=0;
        for(auto&v:res)
        {
            if(v[0]==v[1] && v[1]==v[2])
                ans+=(m[v[0]]*(m[v[0]]-1)*(m[v[0]]-2))/6;
            else if(v[0]==v[1])
                ans+=((m[v[0]]*(m[v[0]]-1))/2)*m[v[2]];
            else if(v[1]==v[2])
                ans+=((m[v[1]]*(m[v[1]]-1))/2)*m[v[0]];
            else 
                ans+=m[v[0]]*m[v[1]]*m[v[2]];
            
        }
        return ans%MOD;
    }
};