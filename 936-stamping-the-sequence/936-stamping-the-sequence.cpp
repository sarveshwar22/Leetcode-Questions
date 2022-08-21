class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        vector<int> res;
        int totalStamp =0;
        while(true)
        {
            int turnStamp =0 ;
            for(int i=stamp.size();i>0;i--)
            {
                for(int j=0;j+i<=stamp.size();j++)
                {
                    string newStamp = string(j,'*')+stamp.substr(j,i)+string(stamp.size()-i-j,'*');
                    auto pos = target.find(newStamp);
                    while(pos!=string::npos)
                    {
                        res.push_back(pos);
                        turnStamp+=i;
                        fill(target.begin()+pos,target.begin()+stamp.size()+pos,'*');
                        pos = target.find(newStamp);
                    }
                }
            }
            totalStamp+=turnStamp;
            if(turnStamp==0)
                break;
        }
        reverse(res.begin(),res.end());
        return totalStamp==target.size()?res:vector<int>();
    }
};