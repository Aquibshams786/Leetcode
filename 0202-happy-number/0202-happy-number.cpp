class Solution {
public:
    bool isHappy(int n) {
        int sum = 0;
        while(sum != 1) {
            sum = 0;
            while(n) {
                sum += pow(n % 10, 2);
                n /= 10;
            }
            n = sum;
            if(sum == 4) return false;
        }
        return true;
    }
};