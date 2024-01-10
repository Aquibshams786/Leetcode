class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        while(nums1.size()>m){
            nums1.pop_back();
        }
        int i=0;
        while(i<nums2.size()){
            nums1.push_back(nums2[i]);
            i++;
        }
        sort(nums1.begin(),nums1.end());
    }
};