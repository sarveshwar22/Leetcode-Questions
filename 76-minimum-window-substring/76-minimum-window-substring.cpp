class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> freqT(256,0);
        vector<int> freqS(256,0);
        for(int i=0;i<t.size();i++)
        {
            freqT[t[i]]++;
        }
        
        int count=0;
        int start=0;
        int ansStart=-1;
        int ansSize=INT_MAX;
        
        for(int i=0;i<s.size();i++)
        {
            freqS[s[i]]++;
            if(freqT[s[i]]!=0 && freqT[s[i]]>=freqS[s[i]])
            {
                count++;
            }
            if(count==t.size())
            {
                while(freqT[s[start]]==0 || freqT[s[start]]<freqS[s[start]])
                {
                    freqS[s[start++]]--;
                }
                if(i-start+1<ansSize)
                {
                    ansSize=i-start+1;
                    ansStart=start;
                }
                
            }
        }
        if(ansStart==-1)
            return "";
        return s.substr(ansStart,ansSize);
    }
};