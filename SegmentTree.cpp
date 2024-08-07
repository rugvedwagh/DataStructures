class NumArray
{
public:
    vector<int> v, tree;
    int n;

    void build(int s, int e, int x)
    {
        if (s == e)
        {
            tree[x] = v[s];
            return;
        }

        int mid = s + (e - s) / 2;

        build(s, mid, 2 * x + 1);
        build(mid + 1, e, 2 * x + 2);

        tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
    }

    NumArray(vector<int> &nums)
    {
        n = nums.size();
        tree.resize(n * 4, 0);
        v = nums;
        build(0, n - 1, 0);
    }

    void update(int s, int e, int x, int index, int val)
    {
        if (index < s or index > e)
        {
            return;
        }

        if (s == e)
        {
            if (s == index)
            {
                tree[x] = val;
            }
            return;
        }

        int mid = s + (e - s) / 2;
        update(s, mid, x * 2 + 1, index, val);
        update(mid + 1, e, x * 2 + 2, index, val);

        tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
    }
    int sumRange(int l, int r, int s, int e, int x)
    {
        if (r < s or l > e)
        {
            return 0;
        }

        if (l <= s and r >= e)
        {
            return tree[x];
        }

        int mid = s + (e - s) / 2;
        int leftsum = sumRange(l, r, s, mid, 2 * x + 1);
        int rightsum = sumRange(l, r, mid + 1, e, 2 * x + 2);

        return leftsum + rightsum;
    }
};
