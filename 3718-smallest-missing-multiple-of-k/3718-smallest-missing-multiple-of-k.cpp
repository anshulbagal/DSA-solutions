class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int x = k;

        while(true){
            bool found = false;

            for(int n : nums){
                if(n == x){
                    found = true;
                    break;
                }
            }

            if(!found){
                return x;
            }

            x += k;
        }
    }
};