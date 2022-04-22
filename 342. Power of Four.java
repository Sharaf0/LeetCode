//16 = 15 + 1
//8 = 6 + 2
class Solution {
    public boolean isPowerOfFour(int n) {
        if(n <= 0) return false;
        long x = (long)n;
        return (x & (x - 1)) == 0 && x % 3 == 1;
    }
}
