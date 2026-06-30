class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int r = board.size();
        int c = board[0].size();

        for(int i = 0 ; i < r; i++)
        {
            for(int j = 0; j < c ; j++)
            {
                if(dfs(board,word,i,j,0)) return true;
            }
        }

        return false;
    }
    bool dfs(vector<vector<char>>& board,string word,int i,int j,int index)
    {
        if(board[i][j]!=word[index])    return false;
        if(index == word.size() - 1)    return true;
        char temp = board[i][j];
        board[i][j] = 0;
        if((i > 0 &&dfs(board,word,i-1,j,index+1))
        ||(i < board.size() - 1 && dfs(board,word,i + 1,j, index + 1)) 
        ||(j > 0 && dfs(board,word,i, j - 1, index + 1)) 
        ||(j < board[0].size() - 1 && dfs(board,word, i,j + 1, index + 1))){
            return true;
        }
        board[i][j] = temp;
        return false;
    }
};