class Solution {
public:
     long divide(long dividend, long divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        int sign = (dividend > 0) ^ (divisor > 0) ? -1 : 1;
        dividend = labs(dividend), divisor = labs(divisor);
        long ans=0;
        while (dividend >= divisor) {
            long curr_divisor = divisor, num_divisor = 1;
            while ((curr_divisor << 1) <= dividend) {
                curr_divisor <<= 1;
                num_divisor <<= 1;
            }
            dividend -= curr_divisor;
            ans +=num_divisor;
        }
        return sign*ans;
    }
};