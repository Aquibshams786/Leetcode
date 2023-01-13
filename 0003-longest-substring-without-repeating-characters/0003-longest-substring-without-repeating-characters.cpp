class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> set;
        int max=0;
        
        int start=0;
        int end=0;
        
        while(start<s.size()){
            auto it = set.find(s[start]);
            
            if(it==set.end()){
                if(start-end+1>max){
                    max=start-end+1;
                }
                set.insert(s[start]);
                start++;
            }
            else{
                set.erase(s[end]);
                end++;
            }
        }
        
        
        
        
        return max;
    }
};