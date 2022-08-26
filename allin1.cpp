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
