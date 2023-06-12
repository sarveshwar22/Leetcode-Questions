class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<int>temp;
        vector<string> res;
        if(nums.size()==0)
            return res;
        int ele = nums[0];
        temp.push_back(ele);
        for(int i=1;i<nums.size();i++)
        {
            if(temp[temp.size()-1]+1==nums[i])
            {
                temp.push_back(nums[i]);
            }
            else
            {
                string str;
                if(temp.size()==1)
                    str = to_string(temp[0]);
                else
                    str = to_string(temp[0])+"->"+to_string(temp[temp.size()-1]);
                res.push_back(str);
                temp.clear();
                temp.push_back(nums[i]);
            }
        }
        string str;
        if(temp.size()==1)
            str = to_string(temp[0]);
        else
            str = to_string(temp[0])+"->"+to_string(temp[temp.size()-1]);
        res.push_back(str);
        
        return res;
    }
};