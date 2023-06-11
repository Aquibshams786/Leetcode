class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int, greater<int> > s1;
        vector<int> ans;
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                if(nums1[i]==nums2[j]){
                    s1.insert(nums1[i]);
                }
            }
        }
        for(auto i:s1){
            ans.push_back(i);
        }
        return ans;
    }
};