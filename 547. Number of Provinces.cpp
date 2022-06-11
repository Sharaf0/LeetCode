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
        q.push(n);
        while(!q.empty()) {
            int current = q.front();
            q.pop();
            if(visited[current])
                continue;
            for(int i = 0; i < n; i ++) {
                if(!visited[i] && isConnected[currentNode][i])
                    q.push(i);
            }
        }
    }
};