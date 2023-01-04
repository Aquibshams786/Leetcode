class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int,int> m;
        for(int i=0;i<tasks.size();i++){
            m[tasks[i]]++;
        }
        // for(auto i:m){
        //     cout<<i.first<<":"<<i.second<<endl;
        // }
        int steps=0;
        for(auto i:m){
            if(i.second==1) return -1;
            else if(i.second%3==0){
                steps+=(i.second/3);
            }
            else{
                steps+=(i.second/3)+1;
            }
        }
        return steps;
    }
};