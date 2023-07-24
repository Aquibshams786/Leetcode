class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        while(nums1.size()!=m){
            nums1.pop_back();
        }
        int i=0;
        while(n>0){
            nums1.push_back(nums2[i]);
            i++;
            n--;
        }
        sort(nums1.begin(),nums1.end());
    }
};