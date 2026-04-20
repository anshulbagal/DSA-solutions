class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();   // avoid size_t issues
        int i = 0, j = n - 1;

        // move j left until color differs from first
        while (colors[j] == colors[0]) {
            j--;
        }

        // move i right until color differs from last
        while (colors[i] == colors[n - 1]) {
            i++;
        }

        return max(j, n - 1 - i);
    }
};