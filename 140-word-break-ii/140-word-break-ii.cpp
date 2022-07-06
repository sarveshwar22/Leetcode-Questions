class Solution {
    unordered_map<string, vector<string>> m;
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
	    if(m.find(s) != m.end())
		    return m[s];
	    vector<string> res;
	    for(auto word : wordDict){
		    if(s.substr(0, word.size()) == word){          
			    if(word.size() == s.size())                
				    res.push_back(word);
			    else{                                       
				    vector<string> tmp = wordBreak(s.substr(word.size()), wordDict);    
				    for(auto t : tmp){                                               
					    res.push_back(word + " " + t);
				    }
			    }
		    }
	    }
	m[s] = res;
	return res;
}
};