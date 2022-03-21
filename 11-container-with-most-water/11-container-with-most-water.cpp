class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int maxans=0;
        int start=0;
        int end=n-1;
        while(start<=end)
        {
            int currans=min(height[start],height[end])*(end-start);
            maxans=max(maxans,currans);
            if(height[end]>height[start])
                start++;
            else
                end--;
        }
        return maxans;
    }
};