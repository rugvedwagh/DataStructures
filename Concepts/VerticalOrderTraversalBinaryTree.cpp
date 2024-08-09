class Solution
{
public:
    map<int, vector<pair<int, int>>> mp;

    void util(TreeNode *node, int pos, int y)
    {
        if (!node)
        {
            return;
        }
        mp[pos].push_back({node->val, y});
        util(node->left, pos - 1, y + 1);
        util(node->right, pos + 1, y + 1);
        return;
    }

    static bool comp(pair<int, int> &a, pair<int, int> &b)
    {
        if (a.second == b.second)
        {
            return a.first < b.first;
        }
        else
        {
            return a.second < b.second;
        }
    }

    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        util(root, 0, 0);
        vector<vector<int>> ans;
        for (auto i : mp)
        {
            sort(i.second.begin(), i.second.end(), comp);
            vector<int> temp;
            for (int j = 0; j < i.second.size(); j++)
            {
                temp.push_back(i.second[j].first);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};
