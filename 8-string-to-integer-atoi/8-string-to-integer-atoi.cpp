class Solution {
public:
    int myAtoi(string s) {
        bool start=false;
        bool sign=true;
        long long int res=0;
        for(char c:s)
        {
            if(!start)
            {
                if(c=='+')
                {
                    sign=true;
                    start=true;
                }
                else if('0'<=c && c<='9')
                {
                    sign=true;
                    start=true;
                    goto bottom;
                }
                else if(c=='-')
                {
                    sign=false;
                    start=true;
                }
                else if(c==' ')
                    continue;
                else
                    return 0;
                    
            }
            else
            {
               if('0'<=c && c<='9')
               {
                   bottom:
                   res*=10;
                   res+=c-'0';
                   if(res>INT_MAX)
                   {
                       if(sign)
                           return INT_MAX;
                       else
                           return INT_MIN;
                   }
               }
                // else if(c==' ')
                //     continue;
                else
                    return sign?res:-res;
            }
        }
        return sign?res:-res;
    }
};