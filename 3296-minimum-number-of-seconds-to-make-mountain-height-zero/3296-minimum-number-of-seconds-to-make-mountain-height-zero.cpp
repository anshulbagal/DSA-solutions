class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        
        long long left = 0;
        long long right = 1e18;
        long long ans = right;

        while(left <= right) {
            long long mid = (left + right) / 2;
            
            long long total = 0;

            for(long long t : workerTimes) {

                long long l = 0, r = mountainHeight;

                while(l <= r) {
                    long long m = (l + r) / 2;
                    long long time = t * (m * (m + 1) / 2);

                    if(time <= mid) {
                        l = m + 1;
                    } else {
                        r = m - 1;
                    }
                }

                total += r;
                if(total >= mountainHeight) break;
            }

            if(total >= mountainHeight) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return ans;
    }
};