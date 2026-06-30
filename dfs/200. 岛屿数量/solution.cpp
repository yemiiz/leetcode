class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int a = grid.size();
        int b = grid[0].size();
        int num = 0;
        for(int i = 0; i < a;i++)
        {
            for(int j = 0; j < b;j++)
            {
                if(grid[i][j] == '1'){
                    num++;
                    dfs(grid,i,j);
                }
                    
            }
        }
        return num;
    }
    void dfs(vector<vector<char>>&grid, int r, int c){
        int a = grid.size();
        int b = grid[0].size();

        grid[r][c] = '0';

        if(r-1>=0 && grid[r-1][c] == '1')   dfs(grid,r-1,c);
        if(r+1<a  && grid[r+1][c] == '1')   dfs(grid,r+1,c);
        if(c-1>=0 && grid[r][c-1] == '1')   dfs(grid,r,c-1);
        if(c+1<b  && grid[r][c+1] == '1')   dfs(grid,r,c+1);

    }
};