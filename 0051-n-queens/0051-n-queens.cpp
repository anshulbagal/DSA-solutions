class Solution {
public:

    vector<vector<string>> ans;

    unordered_set<int> col;
    unordered_set<int> diag1;
    unordered_set<int> diag2;

    void backtrack(int row,
                   int n,
                   vector<string>& board) {

        // all queens placed
        if (row == n) {
            ans.push_back(board);
            return;
        }

        for (int c = 0; c < n; c++) {

            // check attack
            if (col.count(c) ||
                diag1.count(row - c) ||
                diag2.count(row + c)) {
                continue;
            }

            // place queen
            board[row][c] = 'Q';

            col.insert(c);
            diag1.insert(row - c);
            diag2.insert(row + c);

            // next row
            backtrack(row + 1, n, board);

            // remove queen (backtrack)
            board[row][c] = '.';

            col.erase(c);
            diag1.erase(row - c);
            diag2.erase(row + c);
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<string> board(n, string(n, '.'));

        backtrack(0, n, board);

        return ans;
    }
};