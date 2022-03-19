class Solution {
public:
    int reverse(int x) {
        long long int y=0;
        while(x)
        {
            y*=10;
            y+=x%10;
            if((y>(long long int)(1<<30)*2-1)||y<(long long int)(1<<31))
                return 0;
            x/=10;
        }
        return y;
    }
};