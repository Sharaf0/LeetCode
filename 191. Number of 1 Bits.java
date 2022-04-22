public class Solution {
    long getBit(long n, long i) {
        long mask = 1 << i;
        return n & mask;
    }
    public int hammingWeight(int n) {
        int ones = 0;
        for(int i = 0; i < 32; i ++){
            if(getBit((long)n, i) != 0)
                ones ++;
        }
        return ones;
    }
}
