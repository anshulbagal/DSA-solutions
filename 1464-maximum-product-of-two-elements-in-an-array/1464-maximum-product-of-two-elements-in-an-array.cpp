class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi= INT_MIN;
        int mini= INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums[i]> maxi){
                mini = maxi;
                maxi = nums[i];
            }
            else if(nums[i]>mini){
                mini =nums[i];
            }

        }
        int ans= (maxi-1)* (mini -1);
        return ans;

    }
};