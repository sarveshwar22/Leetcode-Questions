class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> m1(256,-1);
        vector<int> m2(256,-1);
        int n1=s.size();
        int n2=t.size();
        if(n1!=n2)
            return false;
        
        for(int i=0;i<n1;i++)
        {
            if(m1[s[i]-' ']!=-1 && m1[s[i]-' ']!=t[i]-' ')
                return false;
            m1[s[i]-' ']=t[i]-' ';
        }
        for(int i=0;i<n1;i++)
        {
            if(m2[t[i]-' ']!=-1 && m2[t[i]-' ']!=s[i]-' ')
                return false;
            m2[t[i]-' ']=s[i]-' ';
        }
        return true;
    }
};