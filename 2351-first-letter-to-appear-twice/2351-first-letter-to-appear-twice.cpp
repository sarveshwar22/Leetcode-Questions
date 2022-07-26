class Solution {
public:
    char repeatedCharacter(string s) {
        vector<bool> visited(26,false);
        for(char ch:s)
        {
            if(visited[ch-'a'])
                return ch;
            visited[ch-'a']=true;
        }
        return 'a';
    }
};