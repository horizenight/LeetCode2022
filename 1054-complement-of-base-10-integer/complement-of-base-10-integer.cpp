class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0) return 1;  
        int result = 0;
        int bitPosition = 0; 

        while (n != 0) {
            if (!(n & 1)) {  
                result |= (1 << bitPosition);  
            }
            n >>= 1; 
            bitPosition++; 
        }

        return result;
    }
};
