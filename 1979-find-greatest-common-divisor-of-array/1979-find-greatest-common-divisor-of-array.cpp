class Solution {
public:
    int findGCD(vector<int>& nums) {
        int n = nums.size();
        int ans;
        sort(nums.begin(),nums.end());
        int smallest_no = nums[0];
        int greatest_no = nums[n-1];
        ans = gcd(greatest_no , smallest_no);
        return ans;



    }
};