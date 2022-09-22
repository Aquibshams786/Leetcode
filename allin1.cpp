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

/// 1791
class Solution
{
public:
    int findCenter(vector<vector<int>> &edges)
    {
        map<int, int> m;
        int n = edges.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < edges[i].size(); j++)
            {
                m[edges[i][j]]++;
            }
        }
        for (auto i : m)
        {
            if (i.second == n)
            {
                return i.first;
            }
        }
        return 0;
    }
};

// 26 aug
// Reordered power of 2

class Solution
{
public:
    bool reorderedPowerOf2(int n)
    {
        string s = to_string(n);
        sort(s.begin(), s.end());
        vector<string> temp;
        for (int i = 0; i <= 30; i++)
        {
            int a = pow(2, i);
            temp.push_back(to_string(a));
        }
        for (int i = 0; i <= 30; i++)
        {
            sort(temp[i].begin(), temp[i].end());
        }
        for (int i = 0; i <= 30; i++)
        {
            if (s == temp[i])
            {
                return 1;
            }
        }

        cout << s;
        return 0;
    }
};

// 1971

class Solution
{
public:
    bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
    {
        vector<int> arr[n];
        for (int i = 0; i < edges.size(); i++)
        {
            arr[edges[i][0]].push_back(edges[i][1]);
            arr[edges[i][1]].push_back(edges[i][0]);
        }

        vector<int> bfs;
        vector<int> vis(n, 0);
        queue<int> q;
        q.push(source);
        vis[source] = 1;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            bfs.push_back(node);

            for (auto it : arr[node])
            {
                if (!vis[it])
                {
                    q.push(it);
                    vis[it] = 1;
                }
            }
        }
        for (int i = 0; i < bfs.size(); i++)
        {
            if (bfs[i] == destination)
            {
                return 1;
            }
        }
        return 0;
    }
};

// 997  aquib
class Solution
{
public:
    int findJudge(int n, vector<vector<int>> &trust)
    {
        vector<int> temp[n + 1];
        for (int i = 0; i < trust.size(); i++)
        {
            temp[trust[i][0]].push_back(trust[i][1]);
        }
        for (int i = 1; i <= n; i++)
        {
            if (temp[i].size() == 0)
            {
                int a = i;
                // cout<<i;
                int count = 0;
                for (int i = 1; i <= n; i++)
                {
                    if (i != a)
                    {
                        for (int j = 0; j < temp[i].size(); j++)
                        {
                            if (temp[i][j] == a)
                            {
                                count++;
                            }
                        }
                    }
                }
                if (count == n - 1)
                {
                    return i;
                }
            }
        }
        return -1;
    }
};

// 1448
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int ans = 0;
    void pre(TreeNode *root, int maxi)
    {
        if (!root)
        {
            return;
        }
        if (root->val >= maxi)
        {
            ans++;
            maxi = root->val;
        }
        pre(root->left, maxi);
        pre(root->right, maxi);
    }
    int goodNodes(TreeNode *root)
    {
        pre(root, INT_MIN);
        return ans;
    }
};

// 108
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    TreeNode *tree(vector<int> nums, int start, int end)
    {
        if (start > end)
        {
            return NULL;
        }
        int mid = (start + end) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        if (start == end)
        {
            return root;
        }
        root->left = tree(nums, start, mid - 1);
        root->right = tree(nums, mid + 1, end);
        return root;
    }

    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        TreeNode *ans = tree(nums, 0, nums.size() - 1);
        return ans;
    }
};

// 637
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    vector<double> averageOfLevels(TreeNode *root)
    {
        vector<double> ans;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            double n = q.size();
            double sum = 0;
            for (int i = 0; i < n; i++)
            {
                TreeNode *temp = q.front();
                q.pop();
                sum = sum + temp->val;
                if (temp->right)
                {
                    q.push(temp->right);
                }
                if (temp->left)
                {
                    q.push(temp->left);
                }
            }
            ans.push_back(sum / n);
        }
        return ans;
    }
};

///////////////162

class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int n = nums.size();
        int a = -1;
        if (n == 1)
            return 0;
        for (int i = 1; i < n - 1; i++)
        {
            if (nums[i - 1] < nums[i] && nums[i] > nums[i + 1])
            {
                a = i;
            }
        }
        if (a == -1)
        {
            if (nums[0] > nums[n - 1])
            {
                return 0;
            }
            return n - 1;
        }
        return a;
    }
};

//////////////215
class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }
};