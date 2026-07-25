class Solution {
public:
    int maxProduct(int n) {
        int largest=-1;
        int secondlargest=-1;
        int ans =0;
        while(n>0){
            int digit= n %10;
            if(digit > largest){
                secondlargest=largest;
                largest=digit;
            }
            else if(digit > secondlargest){
                secondlargest= digit;
            }
            n=n/10;
        }
        ans = largest * secondlargest;
        return ans;

    }
};