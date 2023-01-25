class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string> ans;
        vector<int> temp;
        int n=score.size();
        temp=score;
        sort(temp.begin(),temp.end());
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(temp[i]==score[j]){
                    score[j]=i;
                }
                
            }
        }
        for(int i=0;i<n;i++){
            if(score[i]==n-1){
                string temp1="Gold Medal";
                ans.push_back(temp1);
            }
            else if(score[i]==n-2){
                string temp1="Silver Medal";
                ans.push_back(temp1);
            }
            else if(score[i]==n-3){
                string temp1="Bronze Medal";
                ans.push_back(temp1);
            }
            else{
                string x=to_string(n-score[i]);
                ans.push_back(x);
            }
            
        }
        return ans;
    }
};