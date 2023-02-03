class Solution {
public:
    string convert(string s, int numRows) {
        vector<int> temp;
        int n=s.size();
        if(numRows==1) return s;
        string ans="";
        while(temp.size()<s.length()){
            for(int i=1;i<numRows;i++){
                temp.push_back(i-1);
            }
            for(int i=numRows;i>1;i--){
                temp.push_back(i-1);
            }
        }
        for(int i=0;i<temp.size();i++){
            cout<<temp[i]<<",";
        }
        char A='A';
        ans.append(n,A);
        // for(int i=0;i<ans.length();i++){
        //     cout<<ans[i];
        // }
        
        int p=0;
        int it=0;
        for(int i=1;i<=numRows;i++){
            for(int j=0;j<n;j++){
                if(temp[j]==p){
                    ans[it]=s[j];
                    it++;
                }
            }
            p++;
        }
        
        return ans;
    }
};