class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int ans=0;
        int n=colors.size();
        for(int i=n-1;i>=0;i--){
            if(colors[i] !=colors[0]){
                ans=i;
                break;
            }
        }
        for(int i=0;i<n;i++){
            if(colors[i] !=colors[n-1]){
                ans=max(ans,n-i-1);
            }
        }
        return ans;
        
    }
};