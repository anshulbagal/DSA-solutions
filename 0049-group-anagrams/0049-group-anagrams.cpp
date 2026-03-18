class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       unordered_map<string,vector<string>>mp;//key,value , key (sorted word) value (key k equal k values)
       for(string s: strs){
         string temp =s;
         sort(temp.begin(),temp.end());
         mp[temp].push_back(s);
       }
       vector<vector<string>>ans;
       for( auto &it:mp){
        ans.push_back(it.second);

       }  
       return ans;
    }
};