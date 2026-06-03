class Solution {
public:
    long long solveDirection(vector<int>& Astart,
                             vector<int>& Adur,
                             vector<int>& Bstart,
                             vector<int>& Bdur) {

        int m = Bstart.size();

        vector<pair<int,int>> rides;
        for(int i = 0; i < m; i++) {
            rides.push_back({Bstart[i], Bdur[i]});
        }

        sort(rides.begin(), rides.end());

        vector<long long> prefMinDur(m);
        vector<long long> suffMinOpenDur(m);

        prefMinDur[0] = rides[0].second;

        for(int i = 1; i < m; i++) {
            prefMinDur[i] =
                min(prefMinDur[i - 1],
                    (long long)rides[i].second);
        }

        suffMinOpenDur[m - 1] =
            (long long)rides[m - 1].first +
            rides[m - 1].second;

        for(int i = m - 2; i >= 0; i--) {
            suffMinOpenDur[i] =
                min(suffMinOpenDur[i + 1],
                    (long long)rides[i].first +
                    rides[i].second);
        }

        vector<int> starts;
        for(auto &p : rides) starts.push_back(p.first);

        long long ans = LLONG_MAX;

        for(int i = 0; i < (int)Astart.size(); i++) {

            long long finishA =
                (long long)Astart[i] + Adur[i];

            int pos =
                upper_bound(starts.begin(),
                            starts.end(),
                            finishA)
                - starts.begin() - 1;

            long long cur = LLONG_MAX;

            if(pos >= 0) {
                cur = min(cur,
                          finishA + prefMinDur[pos]);
            }

            if(pos + 1 < m) {
                cur = min(cur,
                          suffMinOpenDur[pos + 1]);
            }

            ans = min(ans, cur);
        }

        return ans;
    }

    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {

        long long ans1 =
            solveDirection(landStartTime,
                           landDuration,
                           waterStartTime,
                           waterDuration);

        long long ans2 =
            solveDirection(waterStartTime,
                           waterDuration,
                           landStartTime,
                           landDuration);

        return (int)min(ans1, ans2);
    }
};