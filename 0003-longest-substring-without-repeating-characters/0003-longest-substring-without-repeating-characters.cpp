class Solution {
public:
    int lengthOfLongestSubstring(string s) {
     set<char>st;
     int l=0 ,maxLen=0;
     for(int r=0;r<s.size();r++){
        while(st.count(s[r])){
            st.erase(s[l]);
            l++;

        }
        st.insert(s[r]);
        maxLen = max(maxLen, r-l+1);//because we want count of elements thats why +1

     } 
     return maxLen;
        
    }
};