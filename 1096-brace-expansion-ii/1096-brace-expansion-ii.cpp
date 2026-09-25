class Solution {
public:
    string s;
    int i;

    set<string> parse() {
        set<string> res;
        set<string> cur = {""};

        while (i < s.size() && s[i] != '}') {
            if (s[i] == ',') {
                res.insert(cur.begin(), cur.end());
                cur = {""};
                i++;
            }
            else {
                set<string> part;

                if (s[i] == '{') {
                    i++;
                    part = parse();
                    i++; // skip '}'
                }
                else {
                    part.insert(string(1, s[i]));
                    i++;
                }

                set<string> temp;
                for (string a : cur)
                    for (string b : part)
                        temp.insert(a + b);

                cur = temp;
            }
        }

        res.insert(cur.begin(), cur.end());
        return res;
    }

    vector<string> braceExpansionII(string expression) {
        s = expression;
        i = 0;

        set<string> ans = parse();

        return vector<string>(ans.begin(), ans.end());
    }
};