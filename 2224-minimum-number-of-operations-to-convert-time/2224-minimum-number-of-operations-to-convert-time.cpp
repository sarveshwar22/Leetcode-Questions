class Solution {
public:
    int convertTime(string current, string correct) {
        int diff = ( ( stoi( correct.substr(0,2) ) - stoi(current.substr(0,2)) ) * 60) + ( stoi( correct.substr(3) ) - stoi( current.substr(3) ) );
        int ans = 0;
        while(diff - 60 >= 0) diff -= 60,ans++;
        while(diff - 15 >= 0) diff -= 15,ans++;
        while(diff - 5 >= 0) diff -= 5,ans++;
        while(diff - 1 >= 0) diff -= 1,ans++;
        
        return ans;
    }
};