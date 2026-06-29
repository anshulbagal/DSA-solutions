class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        vector<string> substrings;

string s = word;
int n = s.size();

for (int i = 0; i < n; i++) {
    string temp = "";
    for (int j = i; j < n; j++) {
        temp += s[j];
        substrings.push_back(temp);
    }
}
    int count = 0;

for (string a : patterns) {
    for (string sub : substrings) {
        if (a == sub) {
            count++;
            break;  // Don't count the same pattern multiple times
        }
    }
}

return count;
    }
};