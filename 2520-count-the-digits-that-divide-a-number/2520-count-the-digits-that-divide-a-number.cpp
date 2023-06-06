class Solution {
public:
    int countDigits(int num) {
        int temp = num;
        int res = 0;
        while(temp)
        {
            res+=num%(temp%10)==0?1:0;
            temp/=10;
        }
        return res;
    }
};