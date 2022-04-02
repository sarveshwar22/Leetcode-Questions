class Solution {
public:
    int minBitFlips(int start, int goal) {
        int xorNum=start^goal;
        int res=0;
        while(xorNum)
        {
            if(xorNum&1)
            {
                res++;
            }
            xorNum>>=1;
        }
        return res;
    }
};