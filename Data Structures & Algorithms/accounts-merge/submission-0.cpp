class Solution {
public:
    vector<int> size, parent;

    void initialise(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    int find(int n) {
        if (parent[n] == n) {
            return n;
        }
        return parent[n] = find(parent[n]);
    }
    void unite(int m, int n) {
        int parent_m = find(m);
        int parent_n = find(n);

        if (parent_m == parent_n) {
            return;
        }
        if (size[parent_m] < size[parent_n]) {
            swap(parent_n, parent_m);
        }
        parent[parent_n] = parent_m;
        size[parent_m] += size[parent_n];
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();

        initialise(n);
        unordered_map<string, int> mpp;

        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string email = accounts[i][j];

                if (mpp.find(email) != mpp.end()) {

                    unite(i, mpp[email]);
                }
                else {
                    mpp[email] = i;
                }
            }
        }
        vector<vector<string>> merge(n);

        for (auto it : mpp) {

            string email = it.first;
            int idx = it.second;

            int root = find(idx);

            merge[root].push_back(email);
        }
        vector<vector<string>> ans;

        for (int i = 0; i < n; i++) {

            if (merge[i].empty()) {
                continue;
            }
            sort(merge[i].begin(), merge[i].end());

            vector<string> account;
            account.push_back(accounts[i][0]); //adding the name


            for (string email : merge[i]) {
                account.push_back(email); //adding the mail
            }

            ans.push_back(account);
        }

        return ans;
    }
};