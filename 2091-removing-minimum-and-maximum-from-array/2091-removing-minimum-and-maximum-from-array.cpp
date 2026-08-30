class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int maxi = INT_MIN;
        int mini = INT_MAX;

        int maxIndex = 0;
        int minIndex = 0;

        // Find maximum, minimum and their indices
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > maxi) {
                maxi = nums[i];
                maxIndex = i;
            }

            if(nums[i] < mini) {
                mini = nums[i];
                minIndex = i;
            }
        }

        int n = nums.size();

        // 1. Remove both from front
        int option1 = max(maxIndex, minIndex) + 1;

        // 2. Remove both from back
        int option2 = n - min(maxIndex, minIndex);

        // 3. Remove one from front and the other from back
        int option3 = min(maxIndex, minIndex) + 1
                    + n - max(maxIndex, minIndex);

        return min(option1, min(option2, option3));
    }
};