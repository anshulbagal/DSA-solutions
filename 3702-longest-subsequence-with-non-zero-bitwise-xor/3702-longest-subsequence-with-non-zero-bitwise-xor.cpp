class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int x = 0;

        for (int num : nums) {
            x ^= num;
        }

        if (x != 0)
            return nums.size();

        if (*max_element(nums.begin(), nums.end()) != 0)
            return nums.size() - 1;

        return 0;
    }
};