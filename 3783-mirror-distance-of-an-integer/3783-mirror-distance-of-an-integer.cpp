class Solution {
private:
    int reverseNumber(int n) {
    int rev=0;
    while(n!=0){
        int digit= n % 10;
        rev=rev * 10 + digit;
        n /= 10;

    }
    return rev;
}
public:
    int mirrorDistance(int n) {
        int ans=0;
  int x = reverseNumber(n);
  ans = abs(x-n);
  return ans;
    }
};