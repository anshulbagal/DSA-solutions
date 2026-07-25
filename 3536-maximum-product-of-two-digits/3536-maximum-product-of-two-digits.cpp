class Solution {
public:
    int maxProduct(int n) {
        vector<int>digits;
        int maxProd= INT_MIN;
        while(n>0){
            int a= n%10;
            n=n/10;
            digits.push_back(a);
            
        }
        for(int i=0;i<digits.size();i++){
            for(int j=i+1;j<digits.size();j++){
                int product = digits[i]*digits[j];
                maxProd = max(product,maxProd);

            }
        }
        return maxProd;
    }
};