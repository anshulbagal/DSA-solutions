class Solution {
public:
    bool isPalindrome(string s) {
        string newStr = "";
        for (char c : s) {
            if (isalnum(c)) {
                newStr += tolower(c);
            }
        }
        string temp = newStr;
        reverse(temp.begin(),temp.end());
        return newStr == temp;
    }
};