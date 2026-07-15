class Solution {
public:
    int gcdOfOddEvenSums(int n) {
      int evensum=0;
      int oddsum=0;
      
      for(int i=1;i<=n;i++){
         oddsum += 2* i -1;
         evensum += 2*i;
      }
      return gcd(oddsum,evensum);

    }
};