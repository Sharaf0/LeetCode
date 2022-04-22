class Solution {
public:
    bool getBit(long long n, int i) {
        long long mask = 1ll << i;
        return n & mask;
    }
    bool isPowerOfTwo(int n) {
        int ones = 0;
        for(int i = 0; i <= 32; i ++){
            if(getBit((long long)n, i) != 0)
                ones ++;
        }
        return ones == 1;
    }
};
