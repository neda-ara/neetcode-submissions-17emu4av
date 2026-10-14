class Solution {
   public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>> adj;

        sort(tickets.rbegin(), tickets.rend());
        for (const auto& ticket : tickets) {
            adj[ticket[0]].push_back(ticket[1]);
        }

        vector<string> res;
        dfs("JFK", adj, res);
        reverse(res.begin(),res.end());
        return res;
    }

    void dfs(string src, unordered_map<string, vector<string>>& adj,
             vector<string>& res) {
       
        while(!adj[src].empty()) {
            string dest = adj[src].back();
            adj[src].pop_back();
            dfs(dest,adj,res);
        }

        res.push_back(src);
    }
};
