class Solution {
public:
    bool checkDivisibility(int n) {
        int x =n;
        int sum=0;
        int product=1;
        int final=0;
        while(x){
            int digit = x % 10;
            x = x/10;
            sum += digit;
            product *=digit;
            final = sum+ product;
            
        }
        if(n % final ==0){
            return true;
        }
        return false;
    }
};