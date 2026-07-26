class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int product=1;
        int third_largest=INT_MIN;
        int second_largest=INT_MIN;
        int first_largest=INT_MIN;
        int first_smallest= INT_MAX;
        int second_smallest=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=first_largest){
                third_largest=second_largest;
                second_largest= first_largest;
                first_largest= nums[i];
            }
            else if( nums[i]>second_largest){
                third_largest=second_largest;
                second_largest=nums[i];
            }
            else if(nums[i]> third_largest ){
                third_largest=nums[i];

            }
            if(nums[i]<first_smallest){
                second_smallest= first_smallest;
                first_smallest= nums[i];
            }
            else if(nums[i]<second_smallest ){
                second_smallest= nums[i];
            }
        }
        product= max(first_largest * second_largest * third_largest, first_smallest * second_smallest * first_largest);
        return product;
    }
};