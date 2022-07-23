class Solution {
    void mergeSort(vector<pair<int,int>>::iterator start,vector<pair<int,int>>::iterator end, vector<int>&res)
    {
        if(end-start<=1)
            return;
        auto mid=start+(end-start)/2;
        
        mergeSort(start,mid,res);
        mergeSort(mid,end,res);
        auto j=mid;auto i=start;
        for(;i<mid&& j<end;)
        {
            if((*i).first<=(*j).first)
            {
                res[(*i).second]+=(j-mid);
                i++;
            }
            else
                j++;
        }
        while(i<mid)
        {
                res[(*i).second]+=(j-mid);
                i++;
        }
        
        inplace_merge(start,mid,end);
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        vector<int>res(n,0);
        
        vector<pair<int,int>> arrMap;
        for(int i=0;i<n;i++)
        {
            arrMap.push_back({nums[i],i});
        }
        mergeSort(arrMap.begin(),arrMap.end(),res);
        return res;
    }
};