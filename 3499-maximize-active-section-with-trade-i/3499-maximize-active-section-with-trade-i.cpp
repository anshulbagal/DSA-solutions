class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();

        // Count original active sections
        int totalOnes = 0;
        for (char c : s)
            if (c == '1')
                totalOnes++;

        // Augment with 1's
        string t = "1" + s + "1";

        vector<pair<char, int>> runs;

        // Run-length encoding
        int cnt = 1;
        for (int i = 1; i < t.size(); i++) {
            if (t[i] == t[i - 1]) {
                cnt++;
            } else {
                runs.push_back({t[i - 1], cnt});
                cnt = 1;
            }
        }
        runs.push_back({t.back(), cnt});

        int ans = totalOnes;

        // Look for 0-1-0 pattern
        for (int i = 1; i + 1 < runs.size(); i++) {
            if (runs[i - 1].first == '0' &&
                runs[i].first == '1' &&
                runs[i + 1].first == '0') {

                ans = max(ans,
                          totalOnes +
                          runs[i - 1].second +
                          runs[i + 1].second);
            }
        }

        return ans;
    }
};