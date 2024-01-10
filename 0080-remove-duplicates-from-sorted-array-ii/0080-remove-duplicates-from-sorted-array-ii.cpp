class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        nums.clear();
        for(auto i:m){
            if(i.second>=2){
                nums.push_back(i.first);
                nums.push_back(i.first);
            }
            else{
                nums.push_back(i.first);
            }
        }
        return nums.size();
    }
};