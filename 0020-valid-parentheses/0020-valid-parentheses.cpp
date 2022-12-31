class Solution {
public:
    bool isValid(string s) {
        // if(s.length()==1) return false;
        // stack<char> st;
         if(s.length() & 1) return false; //odd length strings can't be balanced
        stack<char> st;
        st.push('a'); 
        for(int i=0;i<s.length();i++){
            cout<<s[i];
            if(s[i]=='('||s[i]=='{'||s[i]=='['){
                st.push(s[i]);
            }
            else if((st.top()=='('&&s[i]==')') || (st.top()=='['&&s[i]==']') || (st.top()=='{'&&s[i]=='}')){
                st.pop();
            }
            else{
                cout<<"2";
                return false;
            }
        }
//         for(auto it: s)
//         {
//             if(it=='(' || it=='[' || it=='{'){
//             st.push(it);

//             }
//             else if((it==')' && st.top()=='(') || (it=='}' && st.top()=='{') || (it==']' && st.top()=='['))
//             {
//                 st.pop();
//             }
//             else{
//                 return false;
//             }
//         }
        cout<<st.size();
        if(st.size()==1) return true;
        return false;
    }
};