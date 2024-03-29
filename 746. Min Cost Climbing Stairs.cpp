class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int dp[1001];//min. cost needed to reach i-th step.
        dp[0] = cost[0];
        dp[1] = cost[1];
        
        int steps = cost.size();
        
        cost.push_back(0);
        
        for(int i = 2; i <= steps; i ++) {
            dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
        }
        
        return dp[steps];
    }
};
