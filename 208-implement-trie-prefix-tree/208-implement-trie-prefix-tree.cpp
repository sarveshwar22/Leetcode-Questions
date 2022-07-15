class Trie {
    vector<Trie*> next;
    bool isWord = false;
public:
    Trie() {
        next = vector<Trie*>(26,NULL);
    }
    
    void insert(string word) {
        Trie* node = this;
        for(char ch:word)
        {
            if(node->next[ch-'a']==NULL)
                node->next[ch-'a']=new Trie();
            node=node->next[ch-'a'];
        }
        node->isWord = true;
    }
    
    bool search(string word) {
        Trie* node = this;
        for(char ch:word)
        {
            if(node->next[ch-'a']==NULL)
                return false;
            node=node->next[ch-'a'];
        }
        return node->isWord;
    }
    
    bool startsWith(string prefix) {
        Trie* node = this;
        for(char ch:prefix)
        {
            if(node->next[ch-'a']==NULL)
                return false;
            node=node->next[ch-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */