class Solution {
public:

    void bfs(int src, vector<vector<int>>& adj, vector<int>& dist) {
       
        queue<int>q;
        vector<int>vis(adj.size(), 0);
        dist[src] = 0;
        q.push(src);

        while(!q.empty()) {
            auto node = q.front();
            vis[node] = 1;
            q.pop();

            for(auto it:adj[node]) {
                if(!vis[it]) {
                    dist[it] = min(dist[it], 1 + dist[node]);
                    q.push(it);
                    vis[it] = 1;
                }
            }
        }
}   
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        if(node1 == node2) return node1;
        vector<vector<int>>adj(n);

        for(int i = 0;i<n;i++) {
            if(edges[i]!=-1) adj[i].push_back(edges[i]);
        }

        vector<int>one(n, 1e8), two(n, 1e8);
        bfs(node1, adj, one);
        bfs(node2, adj, two);
        
        
        int node = -1, ans = 1e7;
        for(int i = 0;i<n;i++) {
            if(ans > max(one[i], two[i])) {
                node = i, ans = max(one[i], two[i]);
            }
        }

        return node;


    }
};  