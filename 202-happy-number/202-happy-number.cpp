class Solution {
public:
    bool isHappy(int n) {
        int x=0;
        bool flag=true;
        while(flag || x)
        {
            x=0;
            flag=false;
            while(n)
            {
                x+=(n%10)*(n%10);
                n/=10;
            }
            cout<<x<<" ";
            if(x==1||x==7)
                return true;
            if(x<10)
                return false;
            n=x;
        }
        return false;
    }
};