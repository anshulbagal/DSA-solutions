class Solution {
public:
    int trap(vector<int>& height) {
        int l=0, r=height.size()-1;
        int res=0;
        int leftmax=0 , rightmax=0;
        while(l<r){
            if(height[l]<height[r]){
                leftmax=max(leftmax,height[l]);
                res += leftmax-height[l];
                l++;
            }
            else {
                rightmax=max(rightmax,height[r]);
                res += rightmax - height[r];
                r--;
            }
        }
        return res;
    }
};