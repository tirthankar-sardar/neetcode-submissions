class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses,0);
        vector<vector<int>> adj(numCourses,vector<int>());
        for(int i=0;i<prerequisites.size();i++){
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];

            adj[u].push_back(v);
        }
        for(int i=0;i<adj.size();i++){
            for(int v:adj[i]) indegree[v]++;
        }
        queue<int> q;
        int count=0;
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0){
                q.push(i);
                count++;
            }
        }
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            for(auto v:adj[curr]){
                indegree[v]--;
                if(indegree[v]==0){
                    q.push(v);
                    count++;
                }
            }
        }
        return count==numCourses;
    }
};
