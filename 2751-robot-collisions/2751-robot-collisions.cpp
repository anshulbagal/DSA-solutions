class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        
        vector<tuple<int,int,char,int>> robots;
        
        for(int i = 0; i < n; i++) {
            robots.push_back({positions[i], healths[i], directions[i], i});
        }
        
        sort(robots.begin(), robots.end()); // sort by position
        
        stack<int> st; // stores index in robots vector
        
        vector<int> alive(n, 1);
        
        for(int i = 0; i < n; i++) {
            auto &[pos, health, dir, idx] = robots[i];
            
            if(dir == 'R') {
                st.push(i);
            } else {
                // dir == 'L'
                while(!st.empty()) {
                    int j = st.top();
                    auto &[pos2, health2, dir2, idx2] = robots[j];
                    
                    if(health2 < health) {
                        // R dies
                        alive[j] = 0;
                        st.pop();
                        health--;
                    }
                    else if(health2 > health) {
                        // L dies
                        alive[i] = 0;
                        health2--;
                        break;
                    }
                    else {
                        // both die
                        alive[j] = 0;
                        alive[i] = 0;
                        st.pop();
                        break;
                    }
                }
            }
        }
        
        vector<pair<int,int>> survivors;
        
        for(int i = 0; i < n; i++) {
            if(alive[i]) {
                auto &[pos, health, dir, idx] = robots[i];
                survivors.push_back({idx, health});
            }
        }
        
        sort(survivors.begin(), survivors.end());
        
        vector<int> result;
        for(auto &p : survivors) {
            result.push_back(p.second);
        }
        
        return result;
    }
};