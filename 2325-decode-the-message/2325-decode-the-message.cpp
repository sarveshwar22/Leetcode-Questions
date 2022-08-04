class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char,char> m;
        char s='a';
        for(int i=0;i<key.size();i++)
        {
            if(!m.count(key[i]) && key[i]>='a' && key[i]<='z')
                m[key[i]]=s++;
        }
        string res="";
        for(int i=0;i<message.size();i++)
        {
            if(message[i]>='a' && message[i]<='z')
                res+=m[message[i]];
            else
                res+=message[i];
        }
        return res;
    }
};