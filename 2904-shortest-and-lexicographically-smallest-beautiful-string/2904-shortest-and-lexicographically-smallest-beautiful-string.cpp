class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int minlen=INT_MAX;
        int n= s.length();
        string ans ="";
        
        for(int i =0; i < n ;i++){
            int ones =0;
            for(int j=i;j<n;j++){
                if(s[j]=='1'){
                    ones++;

                }
                if(ones > k){
                    break;
                }
                if(ones == k ){
                    int len = j-i + 1;
                    string curr = s.substr(i,len);

                    if(len < minlen){
                        minlen = len;
                        ans =curr;
                    }
                    else if( len == minlen && curr < ans ){
                        ans = curr;
                    }
                }
            }
        }
        return ans;

    }
};