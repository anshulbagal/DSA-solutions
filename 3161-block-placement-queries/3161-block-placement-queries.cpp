class SegmentTree {
public:
    int n;
    vector<int> tree;

    SegmentTree(int n) {
        this->n = n;
        tree.resize(4 * n, 0);
    }

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
            return;
        }

        int mid = (start + end) / 2;

        if (idx <= mid)
            update(2 * node, start, mid, idx, val);
        else
            update(2 * node + 1, mid + 1, end, idx, val);

        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int idx, int val) {
        update(1, 0, n - 1, idx, val);
    }

    int query(int node, int start, int end, int l, int r) {
        if (r < start || end < l)
            return 0;

        if (l <= start && end <= r)
            return tree[node];

        int mid = (start + end) / 2;

        return max(
            query(2 * node, start, mid, l, r),
            query(2 * node + 1, mid + 1, end, l, r)
        );
    }

    int query(int l, int r) {
        if (l > r) return 0;
        return query(1, 0, n - 1, l, r);
    }
};

class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        const int MAXX = 50000;

        set<int> obstacles;
        obstacles.insert(0);
        obstacles.insert(MAXX);

        for (auto &q : queries) {
            if (q[0] == 1) {
                obstacles.insert(q[1]);
            }
        }

        SegmentTree seg(MAXX + 1);

        auto it = obstacles.begin();
        auto prevIt = it;
        ++it;

        while (it != obstacles.end()) {
            seg.update(*it, *it - *prevIt);
            prevIt = it;
            ++it;
        }

        vector<bool> ans;

        for (int i = (int)queries.size() - 1; i >= 0; i--) {
            auto &q = queries[i];

            if (q[0] == 2) {
                int x = q[1];
                int sz = q[2];

                int bestGap = seg.query(0, x);

                auto it = obstacles.upper_bound(x);
                --it;

                int tailGap = x - *it;

                ans.push_back(max(bestGap, tailGap) >= sz);
            }
            else {
                int pos = q[1];

                auto curr = obstacles.find(pos);
                auto left = prev(curr);
                auto right = next(curr);

                seg.update(*right, *right - *left);

                obstacles.erase(curr);
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};