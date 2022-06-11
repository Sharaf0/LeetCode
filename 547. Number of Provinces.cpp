class Solution {
public:
    vector<int> pset;
    
    int findSet(int a) {
        return (pset[a] == a) ? a : (pset[a] = findSet(pset[a]));
    }
    void unionSet(int a, int b) {
        pset[findSet(a)] = findSet(b);
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        for(int i = 0; i < n; i ++)
            pset.push_back(i);
        
        for(int i = 0; i < n; i ++) {
            for(int j = 0; j < n; j ++) {
                if(isConnected[i][j])
                    unionSet(i, j);
            }
        }

        int cc = 0;
        for(int i = 0; i < n; i ++)
            if(pset[i] == i)
                cc ++;

        return cc;
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int cc = 0;
        for(int i = 0; i < n; i ++) {
            if(!visited[i]) {
                dfs(isConnected, visited, i, n);
                cc ++;
            }
        }
        return cc;
    }
    void dfs(const vector<vector<int>>& isConnected, vector<bool>& visited, int currentNode, int n) {
        if(visited[currentNode]) return;
        visited[currentNode] = true;
        for(int i = 0; i < n; i ++) {
            if(!visited[i] && isConnected[currentNode][i])
                dfs(isConnected, visited, i, n);
        }
    }
    void bfs(const vector<vector<int>>& isConnected, vector<bool>& visited, int currentNode, int n) {
        visited[currentNode] = true;
        queue<int> q;
        q.push(currentNode);
        while(!q.empty()) {
            int current = q.front();
            q.pop();
            
            for(int i = 0; i < n; i ++) {
                if(!visited[i] && isConnected[current][i]) {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
    }
};
