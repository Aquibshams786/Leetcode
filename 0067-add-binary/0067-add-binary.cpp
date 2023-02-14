class Solution {
public:
    string addBinary(string a, string b) {
     string res = "";int carry = 0;
    //  making both strings equal
     while(a.size() < b.size()) a = "0" + a;
     while(b.size() < a.size()) b = "0" + b;
     for(int i = b.size()-1; i>=0 ; i--){
         if(a[i] == '1' && b[i] == '1'){
             if(carry == 0) res = "0" + res;
             else res = "1" + res;
             carry = 1;
         }
         else if((a[i] == '0' && b[i]=='1') || (a[i]=='1' && b[i]=='0')){
             if(carry == 0) res = "1" + res;
             else {
                 res = "0" + res; carry = 1;
             }
         }
         else if (a[i]=='0' && b[i] == '0'){
             if(carry == 0) res = "0" + res;
             else {
                 res = "1" + res; carry = 0;
             }
         }
     }
     if(carry == 1) res = "1" + res;
     return res;
    }
};