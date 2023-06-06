class Solution {
public:
    string categorizeBox(long long length, long long width, long long height, long long mass) {
        if(length>=1e4 || width>=1e4 || height>=1e4 || length*width>=(1e9)/height)
        {
            if(mass>=100)
                return "Both";
            else
                return "Bulky";
        }
        else if(mass>=100)
            return "Heavy";
        else
            return "Neither";
    }
};