class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long int ans=0;
        int n=nums.size();
        int i=0;
        vector<int> temp;
        long long int count=0;
        while(i<n){
            if(nums[i]==0){
                count++;
            }
            else{
                if(count!=0) ans+=(count*(count+1))/2;
                count=0;
            }
            i++;
        }
        if(count!=0) ans+=(count*(count+1))/2;
        cout<<ans<<endl;
        
        return ans;
    }
};