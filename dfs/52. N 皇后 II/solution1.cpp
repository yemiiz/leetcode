class Solution {
public:
    int totalNQueens(int n) {
        int res = 0;
        vector<bool> col(n, false);
        vector<bool> diag1(2 * n, false); // row - col + n
        vector<bool> diag2(2 * n, false); // row + col
        dfs(res, 0, col, diag1, diag2, n);
        return res;
    }

    void dfs(int& res, int row,
             vector<bool>& col, vector<bool>& diag1, vector<bool>& diag2, int n)
    {
        if (row == n)
        {
            res++;
            return;
        }
        for (int c = 0; c < n; c++)
        {
            int d1 = row - c + n;
            int d2 = row + c;
            if (!col[c] && !diag1[d1] && !diag2[d2])
            {
                col[c] = true;
                diag1[d1] = true;
                diag2[d2] = true;

                dfs(res, row + 1, col, diag1, diag2, n);

                // 回溯撤销标记
                col[c] = false;
                diag1[d1] = false;
                diag2[d2] = false;
            }
        }
    }
};