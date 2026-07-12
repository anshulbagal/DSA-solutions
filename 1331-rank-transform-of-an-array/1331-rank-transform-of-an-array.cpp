class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
     vector<int> sortedArr =arr;
     sort(sortedArr.begin(),sortedArr.end());
     sortedArr.erase(unique(sortedArr.begin(),sortedArr.end()),sortedArr.end());
     unordered_map<int,int>rank;
     for(int i=0;i<sortedArr.size();i++){
        rank[sortedArr[i]]= i+1;

     } 
     for(int i=0;i<arr.size();i++){
        arr[i]=rank[arr[i]];
     }  
     return arr;
    }
};