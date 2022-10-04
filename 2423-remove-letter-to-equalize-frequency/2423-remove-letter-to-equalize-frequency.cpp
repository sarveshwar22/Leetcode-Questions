class Solution {
public:
    bool equalFrequency(string word) {
        
        unordered_map<char,int> m;
        for(char ch:word)
        {
            m[ch]++;
        }
        for(int i=0;i<word.size();i++)
        {
            m[word[i]]--;
            if(m[word[i]]==0)
                m.erase(word[i]);
            int temp;
            bool flag=true;
            for(auto ele:m)
            {
                if(flag)
                {
                    temp=ele.second;
                    flag=false;
                    continue;
                }
                if(ele.second!=temp)
                {
                    goto label;
                }
            }
            return true;
            label:
            m[word[i]]++;
        }
        return false;
//         unordered_set<char> s;
//         for(char ch:word)
//         {
//             s.insert(ch);
//         }
//         int n=s.size();
//         int m=word.size();
//         cout<<n<<" "<<m<<endl;
//         if(m==n || m%n==1 || m%n==(n-1))
//         {
//             return true;
//         }
//         if(n==2)
//         {
//             unordered_map<char,int> m;
//             for(char ch:word)
//                 m[ch]++;
//             for(auto ele:m)
//             {
//                 if(ele.second==1){
                    
//                     return true;}
//             }
//         }
        
//         return false;
    }
};