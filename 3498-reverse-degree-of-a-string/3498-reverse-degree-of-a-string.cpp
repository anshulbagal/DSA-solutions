class Solution {
public:
    int reverseDegree(string s) {
        int n = s.length();
        int ans = 0;
        for(int i=0;i<n;i++){
            int reversePos =26 -(s[i]-'a');
            int stringPos = i+1;

            ans += reversePos  * stringPos;
        }
        return ans;
    }
};