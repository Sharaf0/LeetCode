class Solution {
    public int singleNumber(int[] nums) {
        int missingNumber = 0;
        for(int i = 0; i< nums.length; i ++)
            missingNumber = missingNumber ^ nums[i];
        return missingNumber;
    }
}

/*
4,1,2,1,2
100
001
010
001
010
===
100
*/
