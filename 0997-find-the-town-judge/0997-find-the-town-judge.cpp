class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> temp[n+1];
        for(int i=0;i<trust.size();i++){
            temp[trust[i][0]].push_back(trust[i][1]);
        }
        for(int i=1;i<=n;i++){
            if(temp[i].size()==0){
                int a=i;
                // cout<<i;
                int count=0;
                for(int i=1;i<=n;i++){
                    if(i!=a){
                        for(int j=0;j<temp[i].size();j++){
                            if(temp[i][j]==a){
                                count++;
                            }
                        }   
                    }
                }
                if(count==n-1){
                    return i;
                }
            }
        }
        return -1;
    }
};