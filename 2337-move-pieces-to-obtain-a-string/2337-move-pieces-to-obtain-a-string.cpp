class Solution {
public:
    bool canChange(string start, string target) {
        int n = target.size();
        int i=0;
        int j=0;
        while(i<=n && j<=n)
        {
            while(i<n && target[i]=='_')
                i++;
            while(j<n && start[j]=='_')
                j++;
            
            if(i==n||j==n)
            {
                return i==n && j==n;
            }
            
            if(target[i]!=start[j])
                return false;
            if(target[i]=='L')
            {    
                if(j<i)
                    return false;
            }
            else{
                if(i<j)
                    return false;
            }
            i++;
            j++;
        }
        return true;
    }
};