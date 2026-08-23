class Solution {
public:
    bool dfs(vector<vector<int>> &adj, vector<bool> &vis, int node, int parent){
        vis[node] = true;
        for(auto it: adj[node]){
            if(!vis[it]){
                dfs(adj, vis, it, node);
            }
            else if(it != parent) return true;
        }
        return false;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        if(n-1!= m) return false;
        vector<vector<int>> adj(n, vector<int>());
        vector<bool> vis(n, false);
        for(int i=0; i<m; i++){
            int a = edges[i][0];
            int b = edges[i][1];

            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        for(int i=0; i<n; i++){

            if(!vis[i] && dfs(adj, vis, i, -1)){
                return false;
            }
        }
        return true;
    }
};
