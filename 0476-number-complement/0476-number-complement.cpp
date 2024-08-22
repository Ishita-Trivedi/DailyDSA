class Solution {
public:
    int findComplement(int num) {
        if (num == 0) return 1; // Special case for 0
        
        // Create a mask with all bits set to 1 for the significant bits in num
        unsigned int mask = ~0;
        while (mask & num) {
            mask <<= 1;
        }

        // The complement is simply the negation of num masked by the significant bits
        return ~num & ~mask;
    }
};
