class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        if(courses.size() <= 0) return 0;
        sort(courses.begin(), courses.end(), [](const vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });
        priority_queue<int> pq;
        int sum = 0;
        for(auto course : courses) {
            sum += course[0];
            pq.push(course[0]);
            if(sum > course[1]) {
                sum -= pq.top();
                pq.pop();
            }
        }
        return pq.size();
    }
};
