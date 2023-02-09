class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        int n = ideas.size();
        
        unordered_map<string, int> mp;
        
        for (int i=0; i<n; i++){
            mp[ideas[i]]++;
        }
        
        vector<vector<int>> t(26, vector<int>(26,0));
        
        for (int i=0; i<n; i++){
            string word = ideas[i];
            char prefix = word[0];
            string suffix = word.substr(1);
            int prefixIndex = (prefix-'a');
            
            for (int j=0; j<26; j++){
                if (j==prefixIndex) continue;
                char newChar = ('a'+j);
                string newWord = newChar + suffix;
                
                if (mp.find(newWord) != mp.end()) continue;
                
                t[prefixIndex][j] += 1;
            }
        }
        
        long long ans = 0;
        for (int i=0; i<26; i++){
            for (int j=0; j<26; j++){
                if (i==j) continue;
                if (t[i][j]>0){
                    ans += (t[i][j]*t[j][i]);
                }
            }
        }
        
        return ans;
    }
};