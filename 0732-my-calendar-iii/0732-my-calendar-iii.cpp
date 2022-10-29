class MyCalendarThree {
    map <int,int> m;
public:
    int book(int s, int e) {
        m[s]++; 
        m[e]--; 
        int events_on = 0, ans = 0;
        for (auto& x:m)
            ans = max(ans,events_on+=x.second);
        return ans;
    }
};