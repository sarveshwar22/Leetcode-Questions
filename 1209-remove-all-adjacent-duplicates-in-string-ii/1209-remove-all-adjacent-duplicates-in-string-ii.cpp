class Solution {
public:
    string removeDuplicates(string s, int k) {
        int i=0;
        int n=s.size();
        vector<int> count(n);
        for(int j=0;j<n;j++,i++)
        {
            s[i]=s[j];
            count[i]=i>0 && s[i-1]==s[j]?count[i-1]+1:1;
            if(count[i]==k)
            {
                i-=k;
            }
        }
        return s.substr(0,i);
        
    }
};