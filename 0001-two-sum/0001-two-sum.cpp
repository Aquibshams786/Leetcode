class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i;
        int n=nums.size();
        vector<int> ans;
        for(i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]+nums[j]==target){
                    ans.push_back(i);
                    ans.push_back(j);
                    break;
                }
            }
        }
        return ans;
    }
};