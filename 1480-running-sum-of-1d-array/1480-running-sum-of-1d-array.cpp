class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> ans;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<=i;j++){
                sum=sum+nums[j];
                
            }
            ans.push_back(sum);
            sum=0;
        }
        return ans;
    }
};