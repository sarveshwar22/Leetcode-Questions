class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int> not_lost;
        map<int,int> lost;
        
        for(auto x : matches){
            int winner = x[0];
            int loser = x[1];
            
            not_lost[winner]++;
            lost[loser]++;
        }
        vector<int> los;
        for(auto x : lost){
            if(x.second == 1){
                los.push_back(x.first);
            }
        }
        vector<int> win;
        for(auto x : not_lost){
            if(lost[x.first] == 0){
                win.push_back(x.first);
            }
        }
        
        return {win,los};
    }
};