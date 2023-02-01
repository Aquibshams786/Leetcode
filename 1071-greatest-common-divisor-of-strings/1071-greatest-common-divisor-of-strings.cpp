class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        string ans="";
        if((str1+str2)==(str2+str1)){
            int n=gcd(str1.length(),str2.length());
            for(int i=0;i<n;i++){
                ans+=str2[i];
            }
            return ans;
        }
        return ans;
    }
};