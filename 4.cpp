/// container with most water

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int l = 0, r = height.size() - 1, ans = INT_MIN;

        while (l < r)
        {
            int current_area = min(height[l], height[r]) * (r - l);
            ans = max(ans, current_area);
            if (height[l] < height[r])
                l++;
            else
                r--;
        }

        return ans;
    }
};

// 25 AUG
class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        for (int i = 0; i < magazine.length(); i++)
        {
            for (int j = 0; j < ransomNote.length(); j++)
            {
                if (magazine[i] == ransomNote[j])
                {
                    ransomNote.erase(ransomNote.begin() + j);
                }
            }
        }
        if (ransomNote.length() == 0)
        {
            return true;
        }
        return false;
    }
};
