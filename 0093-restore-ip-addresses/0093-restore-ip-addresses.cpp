class Solution {
public:
    vector<string> ans;
    void help(int idx, int k, vector<string> &make, string &s)
    {
        if (idx >= s.size())
        {
            if (k == -1)
            {
                string t;
                for (auto i : make)
                    t.append(i), t.push_back('.');
                t.pop_back();
                ans.push_back(t);
            }
            return;
        }

        if (k < 0)
            return;

        if (s[idx] == '0')
        {
            string t;
            t.push_back(s[idx]);
            make.push_back(t);
            help(idx + 1, k - 1, make, s);
            make.pop_back();
            return;
        }

        for (int i = idx; i < min(idx + 3, (int)s.size()); i++)
        {
            string t = s.substr(idx, i - idx + 1);
            int val = stoi(t);
            if (val >= 0 and val <= 255)
            {
                make.push_back(t);
                help(i + 1, k - 1, make, s);
                make.pop_back();
            }
        }
    }
    vector<string> restoreIpAddresses(string s)
    {
        if (s.size() > 12)
            return {};

        vector<string> make;
        help(0, 3, make, s);
        return ans;
    }
};