class Solution {
    set<vector<int>> ans;
    vector<int> res;
    vector<int> nums;
    int n;
public:
    void f(int index, int lastUsed) {
        if(index == -1) {
            auto q = vector<int>(res);
            sort(q.begin(), q.end());
            ans.insert(q);
            return;
        }
        for(int i = lastUsed + 1; i < n; i ++) {
            int temp = res[index];
            res[index] = nums[i];
            f(index - 1, i);
            res[index] = temp;
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {    
        n = nums.size();
        this->nums = nums;
        ans.insert(vector<int>());
        for(int i = 1; i <= n; i ++) {
            res.clear();
            res.assign(i, 0);
            f(i - 1, -1);
        }
        return vector<vector<int>>(ans.begin(), ans.end());
    }
};
