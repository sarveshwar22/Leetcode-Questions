class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        sort(points.begin(),points.end(),[](vector<int> point1,vector<int> point2){
            return point1[0]*point1[0]+point1[1]*point1[1]<point2[0]*point2[0]+point2[1]*point2[1];
        });
        return vector<vector<int>>(points.begin(),points.begin()+k);
    }
};