class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        vector<int> temp=weights;
        int ans=0;
        sort(temp.begin(),temp.end());
        int low=temp[temp.size()-1];
        int high=accumulate(temp.begin(),temp.end(),0);;
        while(low<high){
            int curr=0;
            int day=1;
            cout<<"{"<<low<<","<<high<<"}";
            int mid=low+(high-low)/2;
            cout<<mid<<":";
            for(int i=0;i<weights.size();i++){
                if(curr+weights[i]>mid){
                    curr=0;
                    day++;
                }
                curr+=weights[i];
            }
            // day++;
            if(day<=days){
                high=mid;
            }
            else{
                low=mid+1;
            }
            cout<<endl;
        }
        return low;
    }
};