class Solution {
public:
    int minElement(vector<int>& nums) {
        int n = nums.size();

        int mini = INT_MAX;

        for(int i = 0; i < n; i++) {
            int sum = 0;

            while(nums[i] != 0) {
                int temp = nums[i] % 10;
                nums[i] = nums[i] / 10;
                sum += temp;
            }

            mini = min(mini, sum);
        }

        return mini;
    }
};