class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses, vector<int>());
        int n = prerequisites.size();
        int count = 0;
        vector<int> ans;
        queue<int> q;
        for(int i=0; i<n; i++){
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];

            adj[b].push_back(a);
        }
        vector<int> indegree(numCourses, 0);
        for(int i=0; i<adj.size(); i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }
        for(int i=0; i<indegree.size(); i++){
            if(indegree[i] == 0){
                q.push(i);
                count++;
                ans.push_back(i);
            }
        }
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(auto it : adj[curr]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                    ans.push_back(it);
                    count++;
                }
            }
        }
        if(count == numCourses){
            return ans;
        } 
        return {};
    }
};
