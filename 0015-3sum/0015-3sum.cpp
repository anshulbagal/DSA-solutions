class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        for (int i = 0; i < nums.size(); i++) {

            // optimization: agar current number > 0 hai to aage sab positive honge
            if (nums[i] > 0) break;

            // skip duplicates for i
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int l = i + 1;
            int r = nums.size() - 1;

            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];

                if (sum < 0) {
                    l++;
                } 
                else if (sum > 0) {
                    r--;
                } 
                else {
                    res.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;

                    // skip duplicates for l
                    while (l < r && nums[l] == nums[l - 1]) l++;

                    // skip duplicates for r
                    while (l < r && nums[r] == nums[r + 1]) r--;
                }
            }
        }

        return res;
    }
};