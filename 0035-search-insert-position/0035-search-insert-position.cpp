class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i,j=0,x=0;
        int n=nums.size();
        for(i=0;i<n;i++){
            if(nums[i]==target){
                j=i;
                x=1;
            }
        }
        if(x==0){
            nums.push_back(target);
            sort(nums.begin(),nums.end());
            for(i=0;i<n+1;i++){
            if(nums[i]==target){
                j=i;
            }
        }
        }
        
       return j;
    }
};