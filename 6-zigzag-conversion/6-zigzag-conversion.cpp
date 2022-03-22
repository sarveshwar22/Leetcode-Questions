class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1)
            return s;
        vector<string>zigzag(numRows);
        bool down=false;
        int j=0;
        for(int i=0;i<s.size();i++)
        {
            zigzag[j].push_back(s[i]);
            if(j==numRows-1)
                down=false;
            else if(j==0)
                down=true;
            if(down)
                j++;
            else
                j--;
        }
        string ans="";
        for(string s:zigzag)
        {
            ans+=s;
        }
        return ans;
    }
};