class Solution {
    int mod=1e9+7;
public:
    int countHousePlacements(int n) {
        int house=1;
        int space=1;
        long long total=house+space;
        for(int i=2;i<=n;i++)
        {
            house=space;
            space=total;
            total=(house+space)%mod;
        }
        return (total*total)%mod;
    }
};