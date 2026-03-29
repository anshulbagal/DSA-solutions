class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        if (s1.size() != s2.size()) return false;

        // group 1: index 0 and 2
        string a = {s1[0], s1[2]};
        string b = {s2[0], s2[2]};

        // group 2: index 1 and 3
        string c = {s1[1], s1[3]};
        string d = {s2[1], s2[3]};

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        sort(c.begin(), c.end());
        sort(d.begin(), d.end());

        return (a == b) && (c == d);
    }
};