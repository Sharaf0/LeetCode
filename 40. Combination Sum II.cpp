class Solution {
public:
    vector<int> res;
    set<vector<int> > sans;
    int target;
    vector<int> candidates;
    
    void f(int sum, int lastUsed) {
        if(sum == target) {
            sans.insert(res);
            return;
        }
        
        for(int i = lastUsed; i < candidates.size(); i ++) {
            if (i > lastUsed && candidates[i] == candidates[i - 1])continue;
            
            if(sum + candidates[i] > target) break;
            
            res.push_back(candidates[i]);
            f(sum + candidates[i], i + 1);
            res.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        this->target = target;
        sort(candidates.begin(), candidates.end());
        this->candidates = candidates;
        f(0, 0);
        return vector<vector<int>>(sans.begin(), sans.end());
    }
};
