class Solution {
public:
    vector<int> res;
    vector<vector<int>> ans;
    int n;
    int k;
    
    void f(int index, int lastUsed) {
        if(index == -1) {
            int sum = accumulate(res.begin(), res.end(), 0);
            if(sum == n) {
                ans.push_back(res);
            }
            return;
        }
        for(int i = lastUsed + 1; i <= 9; i ++) {
            int temp = res[index];
            res[index] = i;
            f(index - 1, i);
            res[index] = temp;
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        this->n = n;
        this->k = k;
        res.assign(k, 0);
        f(k - 1, 0);
        return ans;
    }
};
