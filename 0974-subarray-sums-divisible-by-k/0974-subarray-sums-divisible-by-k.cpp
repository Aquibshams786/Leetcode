class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        int count=0;
        int sum=0;
        map<int,int> m;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int temp=((sum%k)+k)%k;
            m[temp]++;
        }
        for(auto i:m){
            if(i.first==0){
                count+=(i.second*(i.second-1))/2+i.second;
            }
            else{
                count+=(i.second*(i.second-1))/2;
            }
        }
        // int count=-2%2;
        return count;
    }
};