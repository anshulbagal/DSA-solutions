class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> velqoradin = nums;   // required variable
        
        vector<long long> prefixGcd(n);
        long long maxi = nums[0];
        
        for(int i = 0; i < n; i++){
            maxi = max(maxi, (long long)nums[i]);
            prefixGcd[i] = __gcd((long long)nums[i], maxi);
        }
        
        sort(prefixGcd.begin(), prefixGcd.end());
        
        long long ans = 0;
        int l = 0, r = n - 1;
        
        while(l < r){
            ans += __gcd(prefixGcd[l], prefixGcd[r]);
            l++;
            r--;
        }
        
        return ans;
    }
};