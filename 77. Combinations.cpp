class Solution {
public:
    vector<int> res;
    vector<vector<int>> ans;
    int n;
    int k;
    
    void f(int index, int lastUsed) {
        if(index == -1) {
            ans.push_back(res);
            return;
        }
        for(int i = lastUsed + 1; i <= n; i ++) {
            int temp = res[index];
            res[index] = i;
            f(index - 1, i);
            res[index] = temp;
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        this->n = n;
        this->k = k;
        res.assign(k, 0);
        f(k - 1, 0);
        return ans;
    }
};
