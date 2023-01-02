class Solution {
public:
    bool detectCapitalUse(string word) {
        vector<int> v;
        for(int i=0;i<word.length();i++){
            int temp=int(word[i]);
            cout<<temp<<",";
            v.push_back(temp);
        }
        if(v.size()==1) return true;
        for(int i=1;i<v.size();i++){
            if(v[0]>=97 && v[i]<97){
                cout<<"p";
                return false;
            }
            else if(v[1]>=97 && v[i]<97){
                cout<<"q";
                return false;
            }
            else if(v[1]<97 && v[i]>=97){
                cout<<"r";
                return false;
            }
        }
        return true;
    }
};