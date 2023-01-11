class Solution {
public:
    int reverse(int x) {
        int n=x;
        bool neg = n<0;
        n=abs(n);
        
        int ans=0;
        int temp;
        while(n>0)
        {
            temp=n%10;
            if((double)INT_MAX/ans<=10.0)
                return 0;
            ans*=10;
            ans+=temp;
            n/=10;
        }
        
        if(!neg)
        return ans;
        return ans*-1;
    }
};