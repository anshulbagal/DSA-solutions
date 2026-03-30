class Solution {
public:
    int maxArea(vector<int>& heights) {
       int n =heights.size();
       int l=0 , r=n-1;
       int maxArea=0;
       while(l < r){
         int h = min(heights[l],heights[r]);
         int w = r-l;
         int Area = h * w;

         maxArea = max(maxArea, Area);
         if(heights[l] < heights[r]){
            l++;
         }
         else{
            r--;
         }
       }
       return maxArea;
    }
};