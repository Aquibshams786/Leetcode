///container with most water


class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0, r=height.size()-1, ans=INT_MIN;
        
        while(l<r) {
            int current_area=min(height[l], height[r]) * (r-l);
            ans=max(ans, current_area);
            if(height[l]<height[r])
                l++;
            else
                r--;
        }
        
        return ans;
    }
};
