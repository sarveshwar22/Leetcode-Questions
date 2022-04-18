class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        int cmax = 0;
        int n = A.size();
        for (int i = 0; i < n - 2; ++i) {
            cmax = max(cmax, A[i]);
            if (cmax > A[i + 2]) 
                return false;
        }
        return true;

    }
};