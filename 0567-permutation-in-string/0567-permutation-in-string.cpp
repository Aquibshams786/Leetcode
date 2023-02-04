class Solution {
public:
    
//     bool check( string st1,string st2){
//         if(st1.length()!=st2.length()) return false;
//         sort(st1.begin(),st1.end());
//         sort(st2.begin(),st2.end());
//         for(int i=0;i<st1.length();i++){
//             if(st1[i]!=st2[i]) return false;
//         }
        
//         return true;
//     }
    // bool check(map<char,int> m){
    //     for(auto )
    // }
    bool checkInclusion(string s1, string s2) {
        int n=s1.length();
        int n1=s2.length();
        map<char,int> m;
        for(int i=0;i<n;i++){
            m[s1[i]]++;
        }
        for(int i=0;i<n1;i++){
            m[s2[i]]--;
            if(i-n>=0){
                m[s2[i-n]]++;
            }
            int flag=0;
            for(auto i:m){
                if(i.second!=0){
                    flag=1;
                }
            }
            if(flag==0) return true;
        }
        
        // for(int i=0;i<n;i++){
        //     cout<<s1.at(i)<<",";
        // }
        // if(n>m) return false;
        // for(int i=0;i<(m-s1.length()+1);i++){
        //     if(check(s1,(s2.substr(i,s1.length())))) return true;
        // }
        return false;
    }
};