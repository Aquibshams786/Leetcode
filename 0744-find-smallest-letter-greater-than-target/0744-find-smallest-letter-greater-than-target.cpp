class Solution {
public:
    char nextGreatestLetter(vector<char>& l, char target) {
        vector<int> temp;
        for(int i=0;i<l.size();i++){
            temp.push_back(int(l[i]));
        }
        sort(temp.begin(),temp.end());
        for(int i=0;i<temp.size();i++){
            if(temp[i]>int(target)) return temp[i];
        }
        return temp[0];
        
    }
};