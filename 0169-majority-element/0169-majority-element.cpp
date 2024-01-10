class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        int ans=0;
        int max=-1;
        for(auto i:m){
            if(i.second>max){
                max=i.second;
                ans=i.first;
            }
        }
        return ans;
    }
};