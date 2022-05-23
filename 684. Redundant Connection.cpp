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
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        for(int i = 0; i < edges.size(); i ++) {
            auto vs = edges[i];
            pset[vs[0]] = vs[0];
            pset[vs[1]] = vs[1];
        }
        for(int i = 0; i < edges.size(); i ++) {
            auto vs = edges[i];
            if(isSameSet(vs[0], vs[1]))
                return vs;
            unionSet(vs[0], vs[1]);
        }
        return {-1, -1};
    }
};
