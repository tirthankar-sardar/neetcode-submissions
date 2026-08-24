class Solution {
public:
    unordered_map<string, multiset<string>> adj;
    vector<string> ans;

    void dfs(string airport) {
        // Keep taking the lexicographically smallest available ticket
        while (!adj[airport].empty()) {
            string next = *adj[airport].begin();
            adj[airport].erase(adj[airport].begin());

            dfs(next);
        }

        // Add airport after all outgoing tickets are used
        ans.push_back(airport);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {

        for (auto& ticket : tickets) {
            string from = ticket[0];
            string to = ticket[1];

            adj[from].insert(to);
        }

        dfs("JFK");

        reverse(ans.begin(), ans.end());

        return ans;
    }
};