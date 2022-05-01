class Solution {
public:
    int dp[100000][2];
    int f(const string& s, int i, bool lastIsOne) {
        if(i == s.size())
            return 0;
        if(dp[i][lastIsOne] != -1) return dp[i][lastIsOne];
        int s1, s2;
        s1 = s2 = INT_MAX;
        s1 = (s[i] == '0') + f(s, i + 1, true);
        if(!lastIsOne)
            s2 = (s[i] == '1') + f(s, i + 1, false);
        return dp[i][lastIsOne] = min(s1, s2);
    }
    int minFlipsMonoIncr(string s) {
        memset(dp, -1, sizeof(dp));
        return f(s, 0, false);
    }
};
