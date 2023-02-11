class Solution { 
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<pair<int,int>> adj[n];
        for(int i=0;i<redEdges.size();i++)
            adj[redEdges[i][0]].push_back({redEdges[i][1],1});
        for(int i=0;i<blueEdges.size();i++)
            adj[blueEdges[i][0]].push_back({blueEdges[i][1],0});
        vector<int> dist(n,1e9);
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{0,-1}});
        dist[0]=0;
        while(!q.empty())
        {
            int node=q.front().second.first;
            int dis=q.front().first;
            int col=q.front().second.second;
            q.pop();
            for(auto &it:adj[node])
            {
                int adj_node=it.first;
                int wt=it.second;
                if(wt!=col&&adj_node!=-1)
                {
                    q.push({dis+1,{adj_node,wt}});
                    if(dist[adj_node]>dis+1)
                        dist[adj_node]=dis+1;
                    it.first=-1;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            if(dist[i]==1e9)
                dist[i]=-1;
        }
        return dist;
    }
};