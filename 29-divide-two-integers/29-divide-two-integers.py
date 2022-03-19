class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        isNegative = (dividend<0 and divisor>0) or (dividend>0 and divisor<0)
        res=0;
        dividend,divisor=abs(dividend),abs(divisor);
        
        while(dividend >= divisor):
            curr_divisor,num_divisor=divisor,1;
            while(dividend>=curr_divisor):
                dividend-=curr_divisor;
                res+=num_divisor;
                curr_divisor<<=1;
                num_divisor<<=1;
                
        if(isNegative):
            res=-res;
            
        return  min(max(-2147483648, res), 2147483647)