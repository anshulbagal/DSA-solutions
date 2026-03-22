class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>count;
        priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>>minheap;
        for(int n:nums){
            count[n]++;
        }
        for(auto & x:count){
            minheap.push({x.second,x.first});
            if(minheap.size()>k) {
                minheap.pop();
            }}
            vector<int>result;
            while(!minheap.empty()){
            result.push_back(minheap.top().second);
            minheap.pop();};
        
        return result;
        
    }
    
};