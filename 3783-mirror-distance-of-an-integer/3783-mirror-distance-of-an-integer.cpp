class Solution {
private:
    int reverseNumber(int n) {
    string s = to_string(n);
    reverse(s.begin(), s.end());
    return stoi(s);
}
public:
    int mirrorDistance(int n) {
        int ans=0;
  int x = reverseNumber(n);
  ans = abs(x-n);
  return ans;
    }
};