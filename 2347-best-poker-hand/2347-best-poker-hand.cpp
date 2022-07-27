class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        for(int i=1;i<5;i++)
        {
            if(suits[i]!=suits[0])
                goto x;
        }
        return "Flush";
        x:
        unordered_map<int,int> m;
        for(int rank:ranks)
            m[rank]++;
        bool flag = false;
        for(auto ele:m)
        {
            if(ele.second>=3)
                return "Three of a Kind";
            if(ele.second==2)
                flag = true;
        }
        if(flag)
            return "Pair";
        return "High Card";
    }
};