class Solution {
public:
    int numberOfSpecialChars(string word) {
        set<char>st;
        for(char ch:word){
            st.insert(ch);
        }
        int count =0;

        for(char ch ='a';ch <='z';ch++ ){
            if(st.count(ch) && st.count(ch-32)){
                count++;
            }
        }
        return count;
    }
};