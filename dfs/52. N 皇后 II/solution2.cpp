class Solution {
public:
    int totalNQueens(int n) {
        int cnt = 0;
        auto dfs = [&](auto&& self, int row, int col_mask, int diag1_mask, int diag2_mask)->void{
            if(row == n){
                cnt++;
                return;
            }
            int avail = ((1 << n) - 1) & ~(col_mask | diag1_mask | diag2_mask);
            while(avail){
                int lowbit = avail & -avail;
                avail -= lowbit;
                self(self, row+1, col_mask|lowbit, (diag1_mask|lowbit)<<1, (diag2_mask|lowbit)>>1);
            }
        };
        dfs(dfs,0,0,0,0);
        return cnt;
    }
};