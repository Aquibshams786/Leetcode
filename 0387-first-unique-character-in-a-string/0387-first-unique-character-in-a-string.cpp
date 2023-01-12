class Solution {
public:
    int firstUniqChar(string s) {
        map<char,int> m;
        for(int i=0;i<s.length();i++){
            m[s[i]]++;
        }
        // for(auto i:m){
        //     cout<<i.first<<":"<<i.second;
        //     cout<<endl;
        // }
        for(int i=0;i<s.length();i++){
            if(m[s[i]]==1) return i;
        }
        return -1;
    }
};