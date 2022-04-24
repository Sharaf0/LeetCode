//check this great explaination: https://leetcode.com/problems/first-missing-positive/discuss/319270/Explanation-of-crucial-observation-needed-to-deduce-algorithm
class Solution {
    public int firstMissingPositive(int[] nums) {
        int n = nums.length;
        for(int i = 0; i < n; i ++)
            if(nums[i] <= 0 || nums[i] > n)
                nums[i] = n + 1;
        for(int i = 0; i < n; i ++) {
            int c = Math.abs(nums[i]) - 1;
            if(c != n && nums[c] > 0)
                nums[c] *= -1;
        }
        for(int i = 0; i < n; i ++) {
            if(nums[i] > 0)
                return i + 1;
        }
        return n + 1;
    }
}
