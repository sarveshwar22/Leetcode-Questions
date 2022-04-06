class Solution {
public:
    int hammingWeight(uint32_t n) {
        int steps=0;
        while(n)
        {
            n=n&(n-1);
            steps++;
        }
        return steps;
    }
};