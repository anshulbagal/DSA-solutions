class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int totalSum = 0;

        for (int num : nums) {
            totalSum += num;
        }

        int leftSum = 0;
        int rightSum = totalSum;

        vector<int> ans;

        for (int num : nums) {
            rightSum -= num;
            ans.push_back(abs(leftSum - rightSum));
            leftSum += num;
        }

        return ans;
    }
};