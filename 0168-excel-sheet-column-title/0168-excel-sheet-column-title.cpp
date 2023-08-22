class Solution {
public:
    string convertToTitle(int c) {
        string ans="";
        vector<int> temp;
        while(c>26){
            int a=c%26;
            if(a==0){
                temp.push_back(26);
                c=c-1;
            }
            else
                temp.push_back(a);
            c=c/26;
            
        }
        temp.push_back(c);
        for(int i=temp.size()-1;i>=0;i--){
            cout<<temp[i]<<",";
           ans+=(64+temp[i]);
        }
        return ans;
        
    }
};