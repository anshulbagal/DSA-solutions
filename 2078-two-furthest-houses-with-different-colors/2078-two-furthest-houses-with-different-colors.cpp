class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int dis=INT_MIN;
        for(int i=0;i<colors.size();i++){
            for(int j=i+1;j<colors.size();j++){
                if(colors[i] != colors[j]){
                    dis=max(dis,abs(j-i));
                }
            }
        }
        return dis;
    }
};