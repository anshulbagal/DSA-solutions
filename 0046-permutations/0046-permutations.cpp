class Solution {
public:

    vector<vector<int>> ans;

    void backtrack(vector<int>& nums,
                   vector<int>& curr,
                   vector<bool>& used) {

        // permutation complete
        if (curr.size() == nums.size()) {
            ans.push_back(curr);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {

            // skip already used
            if (used[i]) continue;

            // choose
            used[i] = true;
            curr.push_back(nums[i]);

            // explore
            backtrack(nums, curr, used);

            // undo (backtrack)
            curr.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {

        vector<int> curr;
        vector<bool> used(nums.size(), false);

        backtrack(nums, curr, used);

        return ans;
    }
};