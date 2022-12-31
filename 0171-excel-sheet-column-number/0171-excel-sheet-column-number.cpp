class Solution {
public:
    int titleToNumber(string columnTitle) {
        int n=columnTitle.length();
        int temp=0;
        int ans=0;
        for(int i=n-1;i>=0;i--){
            int d=columnTitle[i]-64;
            ans=ans+d*pow(26,temp);
            temp++;
        }
        return ans;
    }
};