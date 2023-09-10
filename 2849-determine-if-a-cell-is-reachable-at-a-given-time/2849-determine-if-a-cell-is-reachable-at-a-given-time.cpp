class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        if(sx==fx && fy==sy) return t!=1;
        // return ((fx<=sx+t && fy<=sy+t)||(fx>=sx-t && fy<=sy+t)||(fx<=sx+t && fy>=sy-t)||(fx>=sx-t && fy>=sy-t));
        return sx-t<= fx && fx <= sx+t && sy-t<=fy && fy<=sy+t;
    }
};