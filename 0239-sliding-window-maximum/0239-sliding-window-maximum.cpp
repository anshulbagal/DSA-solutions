class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq; // store indices
        vector<int> result;

        for (int i = 0; i < nums.size(); i++) {
            // 1. Remove indices out of current window
            if (!dq.empty() && dq.front() == i - k) {
                dq.pop_front();
            }

            // 2. Remove smaller elements (maintain decreasing order)
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }

            // 3. Add current element index
            dq.push_back(i);

            // 4. Add max to result once first window is formed
            if (i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }
        return result;
    }
};
