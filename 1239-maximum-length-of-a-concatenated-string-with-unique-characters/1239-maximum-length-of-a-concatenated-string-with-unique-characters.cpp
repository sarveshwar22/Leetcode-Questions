class Solution 
{
public:
    
    bool check(string &a, string &b)
    {
        vector<int> vis(26, 0);
        for(auto it:a)
            vis[it-'a']++;
        
		//comparing each char of string a with every char of string b
        for(int i=0; i<a.size(); i++)
        {
            if(vis[a[i]-'a'] > 1) return false; //check whether string a contains duplicate characters
            for(int j=0; j<b.size(); j++)
            {
                if(a[i]==b[j]) return false; //check whether string a and b have same characters
            }
        }
        return true;
    }
    
    int f(int i, vector<string>& arr, string str)
    {
        if(i==0)
        {
            if(check(arr[0], str))
                return arr[0].size();
            return 0;
        }
        
        int take=0, not_take=0;
        
        not_take = 0 + f(i-1, arr, str);
        
        if(check(arr[i], str))
            take = arr[i].size() + f(i-1, arr, str+arr[i]);
        
        return max(not_take, take);
    }
    
    int maxLength(vector<string>& arr) 
    {
        return f(arr.size()-1, arr, "");
    }
};