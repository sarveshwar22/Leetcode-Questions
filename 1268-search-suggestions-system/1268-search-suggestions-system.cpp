class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& p, string sw) {
        vector<vector<string>> ans;
		//to arrange the items in p , lexicographically order
        sort(begin(p),end(p));
        //just iterate the searchWord  and every iteration create a substring
        for(int i=0;i<size(sw);++i){
            string s = sw.substr(0,i+1); //creating the substring (prefix) from index 0
			int cnt = 0; // to count the minimum three products with a common prefix
            vector<string> temp;
            for(int j=0;j<size(p) and cnt < 3;++j){
                if(p[j].find(s) == 0){ //if the prefix matches from index 0 then collect the word and put it into the temp vector and increase the count
                    temp.push_back(p[j]);
                    cnt++;
                }
            }
            ans.push_back(temp);  
        }
        return ans;
    }
};