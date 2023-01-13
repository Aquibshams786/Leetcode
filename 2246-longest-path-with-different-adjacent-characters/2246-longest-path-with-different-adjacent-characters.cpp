class Solution {
public:
    int ans;
    int dfs(int node, vector<vector<int>>& graph, string& s) {
        int max1 = 0;
        int max2 = 0;
        for(int& i : graph[node]) {
            int val = dfs(i, graph, s);
            if(s[i] == s[node]) continue;
            if(val > max1) {max2 = max1; max1 = val;}
            else if(val > max2) {max2 = val;}
        }
        ans = max(ans, max1 + max2 + 1);
        return max1 + 1;
    }
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> graph(n, vector<int>());
        for(int i = 1; i < n; i++) graph[parent[i]].push_back(i);
        ans = 1;
        dfs(0, graph, s);
        return ans;
    }
};