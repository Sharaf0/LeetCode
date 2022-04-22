class Solution {
    public boolean hasAlternatingBits(int n) {
        int state = (n & 1);
        n >>= 1;
        while(n != 0) {
            if((n & 1) == state) return false;
            state = n & 1;
            n >>= 1;
        }
        return true;
    }
}
