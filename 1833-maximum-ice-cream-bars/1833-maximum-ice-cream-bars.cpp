class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int sum=0;
        int count=0;
        for(int i=0;i<costs.size();i++){
            sum+=costs[i];
            count++;
            if(sum>=coins){
                break;
            }
        }
        if(sum>coins){
            count--;
        }
        return count;
    }
};