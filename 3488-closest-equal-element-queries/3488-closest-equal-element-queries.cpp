class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        
        unordered_map<int, vector<int>> mp;
        
        // Step 1: store indices
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }
        
        vector<int> ans;
        
        // Step 2: process queries
        for (int q : queries) {
            int val = nums[q];
            auto &v = mp[val];
            
            // Only one occurrence
            if (v.size() == 1) {
                ans.push_back(-1);
                continue;
            }
            
            // Binary search
            int idx = lower_bound(v.begin(), v.end(), q) - v.begin();
            
            int res = INT_MAX;
            
            // Check left neighbor
            int left = v[(idx - 1 + v.size()) % v.size()];
            res = min(res, min(abs(q - left), n - abs(q - left)));
            
            // Check right neighbor
            int right = v[(idx + 1) % v.size()];
            res = min(res, min(abs(q - right), n - abs(q - right)));
            
            ans.push_back(res);
        }
        
        return ans;
    }
};