class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        // map<char,int> m1,m2;
        vector<int> m1(26,0);
        vector<int> m2(26,0);
        vector<int> ans;
        int slen=s.size();
        int plen=p.size();
        if(slen<plen) return ans;
        int left=0,right=0;
        while(right<plen){
            m1[s[right]-'a']++;
            m2[p[right]-'a']++;
            right++;
        }
        
        right--;
        while(right<slen){
            // cout<<left<<",";
            // if(left==6){
            //     for(auto i:m1){
            //         cout<<i.first<<":"<<i.second;
            //         cout<<"--";
            //     }
            //     cout<<endl;
            //     for(auto i:m2){
            //         cout<<i.first<<":"<<i.second;
            //         cout<<"--";
            //     }
            // }
            if(m1==m2) ans.push_back(left);
            m1[s[left]-'a']--;
            // m1.erase(s[left]);
            right++;
            left++;
            if(right!=slen) m1[s[right]-'a']++;
        }
        return ans;
    }
};