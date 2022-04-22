class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        for(int i = 1; i <= nums.size(); i ++)
            sum ^= i;
        for(int i = 0; i < nums.size(); i ++)
            sum ^= nums[i];
        return sum;
    }
};
//0 + 1 + 2 + 3 = 6 - 3 - 0 - 1 = 2
