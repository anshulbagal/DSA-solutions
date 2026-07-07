class Solution {
public:
    long long sumAndMultiply(int n) {
        string s = to_string(n);
        int x=0;
        int sum=0;
        for(char c : s){
            int digi = c-'0';
            if(digi !=0){
                x = x * 10 +digi;
                sum += digi;

            }
        }
        return 1LL * x*sum;
    }
};