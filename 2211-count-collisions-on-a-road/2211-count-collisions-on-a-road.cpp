class Solution {
public:
    int countCollisions(string directions) {
        int n=directions.size();
        int left=0;
        int right=n-1;
        
        while(left<n && directions[left]=='L')
            left++;
        while(right>=0 && directions[right]=='R')
            right--;
        int ans=0;
        for(int i=left;i<=right;i++)
        {
            if(directions[i]!='S')
                ans++;
        }
        return ans;
    }
};