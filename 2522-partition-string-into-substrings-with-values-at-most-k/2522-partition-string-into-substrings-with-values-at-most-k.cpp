class Solution {
public:
    int minimumPartition(string s, int k) {
        long long temp = 0;
        int res = 1;
        for(char ch:s)
        {
            temp = temp*10+ch-'0';
            if(temp>k)
            {
                res++;
                temp = ch-'0';
            }
            if(temp>k)
                return -1;
        }
        return res;
    }
};