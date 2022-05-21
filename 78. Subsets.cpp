class Solution {
    vector<vector<int>> ans;
    vector<int> res;
    vector<int> nums;
    int n;
public:
    void f(int index, int lastUsed) {
        if(index == -1) {
            ans.push_back(res);
            return;
        }
        for(int i = lastUsed + 1; i < n; i ++) {
            int temp = res[index];
            res[index] = nums[i];
            f(index - 1, i);
            res[index] = temp;
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {    
        n = nums.size();
        this->nums = nums;
        ans.push_back({});
        for(int i = 1; i <= n; i ++) {
            res.clear();
            res.assign(i, 0);
            f(i - 1, -1);
        }
        return ans;
    }
};
