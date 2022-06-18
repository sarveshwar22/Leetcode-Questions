class TrieNode
{
    public:
    
    TrieNode* children[27];
    int index;
    TrieNode()
    {
        for(int i=0;i<27;i++)
            children[i]=NULL;
        index=-1;
    }
};
class Trie
{
    public:
    
    TrieNode* root;
    Trie()
    {
        root = new TrieNode();
    }
    
    void insert(string &s,int id)
    {
        TrieNode* curr = root;
        for(auto &ch:s)
        {
            if(curr->children[ch-'a']==NULL)
            {
                curr->children[ch-'a']=new TrieNode();
            }
            curr = curr->children[ch-'a'];
            curr->index = max(curr->index,id);
            
        }
    }
    
    int search(string& s)
    {
        TrieNode* curr = root;
        for(auto& ch:s)
        {
            if(curr->children[ch-'a']==NULL)
                return -1;
            curr = curr->children[ch-'a'];
        }
        return curr->index;
    }
};

class WordFilter {
    Trie* t = new Trie();
        
public:
    WordFilter(vector<string>& words) {
        int id=0;
        string s="";
        
        for(auto &word:words)
        {
            s = "{"+word;
            for(int i = word.size()-1;i>=0;i--)
            {
                s = word[i]+s;
                t->insert(s,id);
            }
            id++;
        }
    }
    
    int f(string prefix, string suffix) {
        string s = suffix+"{"+prefix;
        return t->search(s);
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */