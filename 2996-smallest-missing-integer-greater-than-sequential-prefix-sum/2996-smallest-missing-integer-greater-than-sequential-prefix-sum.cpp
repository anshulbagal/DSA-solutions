class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int prefixsum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1] + 1) {
                prefixsum += nums[i];
            } else
                break;
        }
        while (find(nums.begin(), nums.end(), prefixsum) != nums.end()) {
            prefixsum++;
        }
        return prefixsum;
    }
};