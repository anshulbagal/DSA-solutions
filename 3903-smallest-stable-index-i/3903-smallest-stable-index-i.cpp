class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        
        for(int i=0;i<nums.size();i++){
            int maximum=0;
            maximum = *max_element(nums.begin(),nums.begin() + i +1);// becuase without * it is an iterator hence we do +1
            int minimum =0;
            minimum = *min_element(nums.begin()+i,nums.end());
            int instability_score=0;
            instability_score= maximum -minimum;
            if(instability_score<=k){
                return i;
            }
            
        }
        return -1;
    }
};