struct DSU
{
    int mx;
    vector<int> parent,size;
    
    DSU(int n)
    {
        mx=1;
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=1;i<=n;i++)
            parent[i]=i;
    }
    int leader(int x)
    {
        if(parent[x]==x)
            return x;
        return parent[x]=leader(parent[x]);
    }
    void merge(int x,int y)
    {
        x=leader(x);
        y=leader(y);
        if(x==y)
            return;
        if(size[x]>size[y])
            swap(x,y);
        size[y]+=size[x];
        parent[x] = y;
        mx=max(mx,size[y]);
    }
};
class Solution {
public:
    int validSubarraySize(vector<int>& nums, int threshold) {
        int n=nums.size();
        vector<pair<double,int>> valInd;
        for(int i=0;i<n;i++)
        {
            valInd.push_back({nums[i],i+1});
        }
        sort(valInd.begin(),valInd.end());
        
        vector<bool> active(n+1,false);
        int k=1;
        DSU dsu(n);
        
        for(int i=n-1;i>=0 && k<=n;)
        {
            double kThres = (double)threshold/k;
            while(i>=0 && valInd[i].first>kThres)
            {
                int index = valInd[i].second;
                active[index] = true;
                if(active[index-1])
                    dsu.merge(index,index-1);
                if(active[index+1])
                    dsu.merge(index,index+1);
                i--;
            }
            if(i<n-1 && dsu.mx>=k)
                return k;
            k++;
            
        }
        return -1;
    }
};