class Solution {
public:
    bool isNumber(string s) {
        int n=s.size();
        int i=0;
        while(i<n && isspace(s[i]))
        {
            i++;
        }
        if(i<n && (s[i]=='+'||s[i]=='-'))
        {
            i++;
        }
        int digits=0;
        int dots=0;
        while(i<n)
        {
            if(isdigit(s[i]))
            {
                digits++;
            }
            else if(s[i]=='.')
            {
                dots++;
                if(dots>1)
                    return false;
            }
            else break;
            
            i++;
        }
        if(digits==0)
            return false;
        
        if(s[i]=='e' || s[i]=='E')
        {
            i++;
            
            
            if(i<n && (s[i]=='+'||s[i]=='-'))
            {
                i++;
            }
            int digits=0;
            int dots=0;
            while(i<n)
            {
                if(isdigit(s[i]))
                {
                    digits++;
                }
                else if(s[i]=='.')
                {
                    // dots++;
                    // if(dots>1)
                        return false;
                }
                else break;
                
                i++;
            }
            if(digits==0)
                return false;
        
        }
        
        while(i<n && isspace(s[i]))
        {
            i++;
        }
        return i==n;
    }
};