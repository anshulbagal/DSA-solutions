class Solution {
public:
    int countCommas(int n) {
        int ans =0;
        if(n < 1000){
            return ans ;
        }
        ans = n - 1000 +1;
        return ans;
    }
};