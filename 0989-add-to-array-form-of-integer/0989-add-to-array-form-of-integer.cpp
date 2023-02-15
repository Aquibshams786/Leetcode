class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int carry=0;
        for(int i=num.size()-1;i>=0;i--){
            int temp=num[i]+(k%10)+carry;
            num[i]=temp%10;
            carry=temp/10;
            k=k/10;
        }
        k+=carry;
        while(k>0){
            num.insert(num.begin(),k%10);
            k=k/10;
        }
        return num;
    }
};