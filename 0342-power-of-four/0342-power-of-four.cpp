class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0) return false; // Added this condition
        double value = log2(n);
        if (value != (long long)(value)) return false;
        return ((long long)value % 2 == 0);
    }
};
