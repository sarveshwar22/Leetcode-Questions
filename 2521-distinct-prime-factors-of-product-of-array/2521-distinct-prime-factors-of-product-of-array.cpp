class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        unordered_set<int> s;
        
        for(int num:nums)
        {
            for(int j=2;j*j<=num;j++)
            {
                if(num%j==0)
                {
                    s.insert(j);
                    while(num%j==0)
                        num/=j;
                }
            }
            if(num>1)
                s.insert(num);
        }
        return s.size();
        
    }
};