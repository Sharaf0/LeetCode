class Solution {
    public int rangeBitwiseAnd(int left, int right) {
        long shifted = 1;
        int shifts = 0;
        while(shifted <= right) {
            shifted <<= 1l;
            shifts ++;
        }
        shifts --;
        shifted >>= 1;
        int answer = 0;
        while((shifted & left) == (shifted & right) && shifted != 0) {
            if((shifted & left) != 0)
                answer |= (1 << shifts);
            shifts --;
            shifted >>= 1;
        }
        
        return answer;
    }
}

//2
class Solution {
    public int rangeBitwiseAnd(int left, int right) {
        int shifts = 0;
        while(left != right) {
            left >>= 1;
            right >>= 1;
            shifts ++;
        }
            
        return left << shifts;
    }
}

//3
//Brian Kernighan's algorithm:
//http://graphics.stanford.edu/~seander/bithacks.html#CountBitsSetKernighan
class Solution {
    public int rangeBitwiseAnd(int left, int right) {
        while(left < right)
            right = right & (right - 1);
        return left & right;
    }
}
