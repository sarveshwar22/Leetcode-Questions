class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        
        int mid=(n1+n2)/2;
        if(n1>n2)
            return findMedianSortedArrays(nums2,nums1);
        int l=0;
        int r=n1;
        while(l<=r)
        {
            int cut1=(l+r)/2;
            int cut2=mid-cut1;
            int l1=(cut1-1>=0)?nums1[cut1-1]:INT_MIN,
            r1=(cut1<n1)?nums1[cut1]:INT_MAX,
            l2=(cut2-1>=0)?nums2[cut2-1]:INT_MIN,
            r2=(cut2<n2)?nums2[cut2]:INT_MAX;
            if(l1>r2)
                r=cut1-1;
            else if(l2>r1)
                l=cut1+1;
            else
                return ((n1+n2)%2==0?((max(l1,l2)+min(r1,r2))/2.0):min(r1,r2));
        }
        return 0;
    }
};