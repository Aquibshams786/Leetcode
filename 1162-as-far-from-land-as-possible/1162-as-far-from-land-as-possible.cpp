class Solution {
public:
    vector<int> dx={0,0,1,-1};
    vector<int> dy={-1,1,0,0};
    int maxDistance(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                    grid[i][j]=2;
                }
            }
        }
        if(q.size()==r*c || q.size()==0) return -1;
        int max=0;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                auto node = q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    int next_i=node.first+dx[i];
                    int next_j=node.second+dy[i];
                    if((next_i>=0 && next_j>=0) && (next_i<r && next_j<c)){
                        if(grid[next_i][next_j]==0){
                            q.push({next_i,next_j});
                            grid[next_i][next_j]=2;
                        }
                    }
                }
            }
            max++;
        }
        return max-1;
    }
};