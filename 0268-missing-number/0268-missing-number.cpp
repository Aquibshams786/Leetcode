class Solution {
public:
    int missingNumber(vector<int>& nums) {
        map<int,int> m;
        for(int i=0;i<=nums.size();i++){
            m[i]++;
        }
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        for(auto i:m){
            if(i.second==1) return i.first;
        }
        return 0;
    }
};