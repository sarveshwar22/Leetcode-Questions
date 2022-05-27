class Solution {
public:
    int numberOfSteps(int num) {
        int res=0;
        while(num)
        {
            res+=(num&1)?2:1;
            num>>=1;
        }
        return res==0?0:res-1;
    }
};