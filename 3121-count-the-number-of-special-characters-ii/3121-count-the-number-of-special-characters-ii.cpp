class Solution {
public:
    int numberOfSpecialChars(string word) {
        
        vector<int> lastLower(26, -1);
        vector<int> firstUpper(26, INT_MAX);

        for(int i = 0; i < word.size(); i++) {

            if(islower(word[i])) {
                lastLower[word[i] - 'a'] = i;
            }
            else {
                firstUpper[word[i] - 'A'] = min(firstUpper[word[i] - 'A'], i);
            }
        }

        int count = 0;

        for(int i = 0; i < 26; i++) {

            if(lastLower[i] != -1 &&
               firstUpper[i] != INT_MAX &&
               lastLower[i] < firstUpper[i]) {

                count++;
            }
        }

        return count;
    }
};