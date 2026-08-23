class Solution {
public:
    vector<int> parent;
    vector<int> sz;
    int count = 0;
    int findparent(int node){
        if(parent[node] == node){
            return node;
        } 
        return parent[node]=findparent(parent[node]);
    }
    void dsunion(int a, int b){
        a = findparent(a);
        b = findparent(b);

        if(a==b) return;

        if(sz[a] >= sz[b]){
            sz[a] += sz[b];
            sz[b] = 0;
            parent[b] = a;
        }
        else{
           sz[b] += sz[a];
            sz[a] = 0;
            parent[a] = b; 
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        sz.resize(n, 1);
        for(int i=0; i<n; i++){
            parent[i] = i;
        }
        for(int i=0; i<edges.size(); i++){
            int a = edges[i][0];
            int b = edges[i][1];

            dsunion(a, b);
        }
        for(int i=0; i<n; i++){
            if(sz[i] != 0){
                count++;
            }
        }
        return count;
    }
};
