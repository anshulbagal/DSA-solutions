class Solution {
public:
    struct Node {
        int len;
        char leftChar, rightChar;
        int leftMax, rightMax, best;

        Node() {
            len = 0;
            leftChar = rightChar = '#';
            leftMax = rightMax = best = 0;
        }

        Node(char c) {
            len = 1;
            leftChar = rightChar = c;
            leftMax = rightMax = best = 1;
        }
    };

    vector<Node> tree;
    string s;

    Node merge(Node a, Node b) {
        if (a.len == 0) return b;
        if (b.len == 0) return a;

        Node res;
        res.len = a.len + b.len;

        res.leftChar = a.leftChar;
        res.rightChar = b.rightChar;

        res.leftMax = a.leftMax;
        res.rightMax = b.rightMax;
        res.best = max(a.best, b.best);

        // If boundary characters are same,
        // the repeating substring can cross the boundary.
        if (a.rightChar == b.leftChar) {
            res.best = max(res.best, a.rightMax + b.leftMax);

            if (a.leftMax == a.len)
                res.leftMax = a.len + b.leftMax;

            if (b.rightMax == b.len)
                res.rightMax = b.len + a.rightMax;
        }

        return res;
    }

    void build(int node, int l, int r) {
        if (l == r) {
            tree[node] = Node(s[l]);
            return;
        }

        int mid = (l + r) / 2;

        build(node * 2, l, mid);
        build(node * 2 + 1, mid + 1, r);

        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    void update(int node, int l, int r, int idx, char c) {
        if (l == r) {
            tree[node] = Node(c);
            return;
        }

        int mid = (l + r) / 2;

        if (idx <= mid)
            update(node * 2, l, mid, idx, c);
        else
            update(node * 2 + 1, mid + 1, r, idx, c);

        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    vector<int> longestRepeating(string s, string queryCharacters,
                                 vector<int>& queryIndices) {

        this->s = s;

        int n = s.size();
        tree.resize(4 * n);

        build(1, 0, n - 1);

        vector<int> ans;

        for (int i = 0; i < queryIndices.size(); i++) {
            int idx = queryIndices[i];
            char c = queryCharacters[i];

            update(1, 0, n - 1, idx, c);

            ans.push_back(tree[1].best);
        }

        return ans;
    }
};