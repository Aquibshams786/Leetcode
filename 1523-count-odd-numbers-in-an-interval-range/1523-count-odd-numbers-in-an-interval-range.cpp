class Solution {
public:
    bool isOdd(int temp){
        if(temp%2==0) return false;
        return true;
    }
    int countOdds(int low, int high) {
        int count=0;
        for(int i=low;i<=high;i++){
            if(isOdd(i)) count++;
        }
        return count;
    }
};