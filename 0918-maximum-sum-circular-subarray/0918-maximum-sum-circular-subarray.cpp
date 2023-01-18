class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        vector<int> temp;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            temp.push_back(-nums[i]);
        }
        
        
        int maxi=0;
        int curr=0;
        for(int i=0;i<nums.size();i++){
            curr=curr+nums[i];
            if(curr>maxi){
                maxi=curr;
            }
            if(curr<0){
                curr=0;
            }
        }
        
        int max=0;
        curr=0;
        for(int i=0;i<temp.size();i++){
            curr=curr+temp[i];
            if(curr>max){
                max=curr;
            }
            if(curr<0){
                curr=0;
            }
        }
        sort(nums.begin(),nums.end());
        if(nums[nums.size()-1]<0){
            return nums[nums.size()-1];
        }
        if(maxi>(sum-(-max))){
            return maxi;
        }
        return sum-(-max);
    }
};