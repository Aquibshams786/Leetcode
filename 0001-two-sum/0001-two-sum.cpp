class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i;
        int n=nums.size();
        for(i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]+nums[j]==target){
                    nums[0]=i;
                    nums[1]=j;
                    break;
                }
            }
        }
        vector<int>::iterator it1, it2;
 
    it1 = nums.begin();
    it2 = nums.end();
    it1++;
    it1++;
 
    nums.erase(it1, it2);
        return nums;
    }
};