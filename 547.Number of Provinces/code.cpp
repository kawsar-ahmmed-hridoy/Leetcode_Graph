class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, vector<bool> &vis, int src) {
        vis[src] = true;
        for (int it = 0; it < isConnected[src].size(); ++it) {
            if (isConnected[src][it] == 1 && !vis[it]) {
                dfs(isConnected, vis, it);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int size = isConnected.size();
        vector<bool> vis(size, false);
        int count = 0;
        
        for (int i = 0; i < size; i++) {
            if (vis[i] == false) {
                count++;
                dfs(isConnected, vis, i);
            }
        }
        
        return count;
    }
};
