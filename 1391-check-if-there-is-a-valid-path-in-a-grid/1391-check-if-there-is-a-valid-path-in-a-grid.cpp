class Solution {
public:
    // directions: left, right, up, down
    vector<vector<int>> dirs = {
        {0, -1}, {0, 1}, {-1, 0}, {1, 0}
    };

    // For each street type, which directions are allowed
    vector<vector<int>> street = {
        {},             // dummy for 0-indexing
        {0, 1},         // type 1 -> left, right
        {2, 3},         // type 2 -> up, down
        {0, 3},         // type 3 -> left, down
        {1, 3},         // type 4 -> right, down
        {0, 2},         // type 5 -> left, up
        {1, 2}          // type 6 -> right, up
    };

    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>> q;
        vector<vector<int>> vis(m, vector<int>(n, 0));

        q.push({0, 0});
        vis[0][0] = 1;

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            // reached destination
            if (x == m - 1 && y == n - 1) return true;

            int type = grid[x][y];

            // explore only valid directions for current street
            for (int d : street[type]) {
                int nx = x + dirs[d][0];
                int ny = y + dirs[d][1];

                if (nx < 0 || ny < 0 || nx >= m || ny >= n || vis[nx][ny])
                    continue;

                int nextType = grid[nx][ny];

                // opposite direction must exist in next cell
                int opposite;
                if (d == 0) opposite = 1;      // left -> right
                else if (d == 1) opposite = 0; // right -> left
                else if (d == 2) opposite = 3; // up -> down
                else opposite = 2;             // down -> up

                bool connected = false;
                for (int nd : street[nextType]) {
                    if (nd == opposite) {
                        connected = true;
                        break;
                    }
                }

                if (connected) {
                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }

        return false;
    }
};