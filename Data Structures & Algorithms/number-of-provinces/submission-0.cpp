class Solution {
public:
    vector<int> parent, size;
    void initialise(int n){
        parent.resize(n);
        size.resize(n, 1);
        for(int i=0; i<n; i++){
            parent[i] = i;
        }
    }
    int findParent(int node){
        if(parent[node] == node){
            return node;
        }
        return parent[node] = findParent(parent[node]);
    }
    void unite(int a, int b){
        int parent_a = findParent(a);
        int parent_b = findParent(b);

        if(parent_a == parent_b) return;
        if(size[parent_a] < size[parent_b]){
            swap(parent_b, parent_a);
        }
        parent[parent_a] = parent_b;
        size[parent_a] += size[parent_b];
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        initialise(n);
        int count = 0;

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(isConnected[i][j] == 1){
                    unite(i, j);
                }
            }
        }
        for(int i=0; i<n; i++){
            if(parent[i] == i){
                count++;
            }
        }
        return count;
    }
};