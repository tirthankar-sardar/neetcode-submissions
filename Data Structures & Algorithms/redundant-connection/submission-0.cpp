class Solution {
public:
    vector<int> parent, size;
    void initialise(int n){
        parent.resize(n+1);
        size.resize(n+1, 1);
        for(int i=0; i<n; i++){
            parent[i] = i;
        }
    }
    int find(int node){
        if(parent[node] == node){
            return node;
        }
        return parent[node] = find(parent[node]);
    }
    bool unite(int a, int b){
        int parent_a = find(a);
        int parent_b = find(b);
        if(parent_a == parent_b) return false;
        if(size[parent_a] < size[parent_b]){
            swap(parent_a, parent_b);
        }
        parent[parent_b] = parent_a;
        size[parent_a] += size[parent_b];
        return true;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        initialise(n);
        for(auto it : edges){
            int u = it[0];
            int v = it[1];

            if(!unite(u,v)){
                return it;
            }
        }
        return {};
    }
};