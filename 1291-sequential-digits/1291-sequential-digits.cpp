class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {

        string digits = "123456789";
        vector<int> ans;

        // Length of the sequential number
        for (int len = 2; len <= 9; len++) {

            // Starting index
            for (int start = 0; start + len <= 9; start++) {

                // Extract substring
                string s = digits.substr(start, len);

                // Convert string to integer
                int num = stoi(s);

                // Check if it lies in the range
                if (num >= low && num <= high)
                    ans.push_back(num);
            }
        }

        return ans;
    }
};