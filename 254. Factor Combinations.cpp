class Solution {
public:
    void f(int num, int index, vector<int>& result, vector<vector<int>>& results) {
        if(num == 1) {
            if(result.size() > 1) {
                results.push_back(result);
            }
            return;
        }
        for(int i = index; i <= num; i ++) {
            if(num % i == 0) {
                result.push_back(i);
                f(num / i, i, result, results);
                result.pop_back();
            }
        }
    }
    
    vector<vector<int>> getFactors(int n) {
        vector<int> result;
        vector<vector<int>>results;
        f(n, 2, result, results);
        return vector<vector<int>>(results.begin(), results.end());
    }
};
