class Solution {
public:
    vector<int> res;
    set<vector<int> > sans;
    int target;
    vector<int> candidates;
    
    void f(int sum) {
        if(sum == target) {
            vector<int> v(res);
            sort(v.begin(), v.end());
            sans.insert(v);
            return;
        }
        
        for(int i = 0; i < candidates.size(); i ++) {
            //if (i > 0 && candidates[i] == candidates[i - 1])
            //    continue;
            
            if(sum + candidates[i] > target) break;
            
            res.push_back(candidates[i]);
            f(sum + candidates[i]);
            res.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        this->target = target;
        sort(candidates.begin(), candidates.end());
        this->candidates = candidates;
        f(0);
        return vector<vector<int>>(sans.begin(), sans.end());
    }
};
