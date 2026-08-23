class Solution {
public:
    bool dfs(int i, vector<vector<int>> &adj, vector<int> &visited, vector<int> &pathVisited){
        visited[i] = true;
        pathVisited[i] = true;

        for(int n : adj[i]){
            if(!visited[n]){
                if(dfs(n, adj, visited, pathVisited)){
                    return true;
                }
            }
            else if(pathVisited[n]){
                return true;
            }
        }
        pathVisited[i] = 0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto it : prerequisites){
            int a = it[0];
            int b = it[1];

            adj[b].push_back(a);
        }
        vector<int> visited(numCourses, 0);
        vector<int> pathVisited(numCourses, 0);

        for(int i=0; i<numCourses; i++){
            if(!visited[i]){
                if(dfs(i, adj, visited, pathVisited)){
                    return false;
                }
            }
        }
        return true;
    }
};