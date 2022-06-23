class Solution {
public:
    int minOperations(vector<string>& logs) {
        
        stack<string>st;
        for(int i=0; i<logs.size(); i++){
            if(logs[i] == "../" and !st.empty()){
                st.pop();
            }else if(logs[i] == "./" and logs[i] != "../"){
                continue;
            }else if(logs[i] != "../") {
                st.push(logs[i]);
            }
        }
        
        return st.size();
    }
};