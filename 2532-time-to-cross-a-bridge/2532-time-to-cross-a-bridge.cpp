class Solution {
public:
    int findCrossingTime(int n, int k, vector<vector<int>>& time) {
        priority_queue<vector<int>> waiting;//time to ready,side,efficiency,index
        priority_queue<vector<int>> ready;//side,efficiency,index
        
        for (int i = 0; i < k; i++)
            waiting.push({0, 0, time[i][0] + time[i][2], i});
        int timestamp = 0;
        int remaining_boxes_on_right_side = n;
        
        while (n) {  
            if (ready.empty() && timestamp < -waiting.top()[0])
                timestamp = -waiting.top()[0];
            
            while (!waiting.empty() && timestamp >= -waiting.top()[0]) {
                vector<int> curW = waiting.top();
                waiting.pop();
                ready.push({curW[1], curW[2],curW[3]});
            }
            auto curR = ready.top();
            ready.pop();
            int side = curR[0];  
            int i = curR[2];  
            
            if (side == 0) { 
                if (remaining_boxes_on_right_side == 0)
                    continue;
                else
                    remaining_boxes_on_right_side--;     
                timestamp += time[i][0];                     
            } 
            else {
            timestamp += time[i][2];       
            n--;
            }
            
            if (side == 1)
                waiting.push({-(timestamp+time[i][3]),0,curR[1],i});
            else
                waiting.push({-(timestamp+time[i][1]),1,curR[1],i});
        }
        return timestamp;
    }
};