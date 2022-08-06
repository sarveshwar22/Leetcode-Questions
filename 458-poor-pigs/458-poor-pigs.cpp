class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int res=0;
        while(pow(minutesToTest/minutesToDie+1,res)<buckets)
            res++;
        return res;
    }
};