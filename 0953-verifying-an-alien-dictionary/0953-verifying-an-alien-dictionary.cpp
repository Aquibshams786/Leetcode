class Solution {
public:
    unordered_map<char,int> m;
    
    bool check(string word1,string word2){
        int d=min(word1.length(),word2.length());
            for(int j=0;j<d;j++){
                if(m[word1[j]]<m[word2[j]]) return true;
                else if(m[word1[j]]>m[word2[j]]) return false;
            }
            if(word1.size()>word2.size()) return false;
            return true;
    }
    
    bool isAlienSorted(vector<string>& words, string order) {
        int n=words.size();
        bool ans=true;
        
        for(int i=0;i<order.size();i++){
            m[order[i]]=i+1;
        }
        for(int i=0;i<n-1;i++){
            bool ans=check(words[i],words[i+1]);
            if(ans==false) return false;
        }
        return true;
        
    }
};