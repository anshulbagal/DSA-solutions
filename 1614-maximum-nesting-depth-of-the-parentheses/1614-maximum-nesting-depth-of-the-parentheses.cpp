class Solution {
public:
    int maxDepth(string s) {
       int maxd =0;
       int currd =0;
       for(char c : s){
        if(c == '('){
            currd++;
            maxd = max(currd,maxd);
        }
        else if(c == ')'){
            currd--;
        }
       } 
       return maxd;
    }
};