class Solution {
public:
    
    int binary(vector<int> arr,int left,int right,int target){
       while(left<=right){
             int mid=(left+right)/2;
             if(arr[mid]==target){
                    return mid;
                }
                else if(arr[mid]<target){
                    left=mid+1;
                    binary(arr,left,right,target);
                }
                else{
                    right=mid-1;
                    binary(arr,left,right,target);
                }
        }
       
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        int ans=binary(nums,0,nums.size()-1,target);
        return ans;
        
    }
};