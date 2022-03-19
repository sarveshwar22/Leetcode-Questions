class Solution {
public:
    double myPow(double x, int n) {
        if(n==0)
            return 1.0;
        if(n==INT_MIN)
        {
            if(x>-1 && x<1)
                return INT_MAX;
            else if(x==-1 || x==1)
                return 1;
            else
                return 0;
        }
        if(n<0)
        {
            return 1.0/myPow(x,-n);
        }
        if(n%2)
        {
            return x*myPow(x,n-1);
        }
        else
            return myPow(x*x,n/2);
    }
};