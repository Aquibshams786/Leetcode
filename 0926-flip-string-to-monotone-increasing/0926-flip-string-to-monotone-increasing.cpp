class Solution {
public:
    int minFlipsMonoIncr(string s) {
        
        int totalZero = 0;
        int leftOne = 0;
        int rightZero = 0;

        int n = s.length();

        for(int i=0;i<n;i++){
            if(s[i] == '0')
                totalZero++;
        }

        
        rightZero = totalZero;
        int ans = rightZero;


        for(int i=0;i<n;i++){
            if(s[i]== '0' ){
                rightZero--;
            }else{
                leftOne++;
            }

            ans = min(ans, leftOne+rightZero);

        }

        return ans;

    }
};