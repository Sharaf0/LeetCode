class Solution {
public:
    map<int, int> pset;
    
    void initSet(vector<int> nums) {
        for(int i = 0; i < nums.size(); i ++) {
            pset[nums[i]] = nums[i];
        }
    }
    
    int findSet(int a) {
        return (pset[a] == a) ? a : (pset[a] = findSet(pset[a]));
    }
    
    bool isSameSet(int a, int b) {
        return findSet(a) == findSet(b);
    }
    
    void unionSet(int a, int b) {
        pset[findSet(a)] = findSet(b);
    }
    
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        initSet(nums);
        for(int i = 0; i < n; i ++) {
            int cur = nums[i];
            if(pset.count(cur - 1)) {
                unionSet(cur, cur - 1);
            }
            if(pset.count(cur + 1)) {
                unionSet(cur, cur + 1);
            }
        }
        map<int, int> parents;
        int mx = 0;
        for(map<int, int>::iterator it = pset.begin(); it != pset.end(); it ++)
            pset[it->first] = findSet(it->first);
        for(map<int, int>::iterator it = pset.begin(); it != pset.end(); it ++) {
            auto st = findSet(it->second);
            parents[st]++;
            mx = max(mx, parents[st]);
        }
        return mx;
    }
};
