class TicTacToe {
private:
    int board[200][200] = {0};
    int size;
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        size = n;
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int check(int row, int col, int player) {
        bool flag = true;
        for(int i = 0; i < size; ++i)
        {
            if(board[i][col] != player)
            {
                flag = false;
                break;
            }
        }
        if(flag) return player;
        flag = true;
        for(int i = 0; i < size; ++i)
        {
            if(board[row][i] != player)
            {
                flag = false;
                break;
            }
        }
        if(flag) return player;
        flag = true;
        for(int i = 0; i < size; ++i)
        {
            if(row + col - i < size && row + col -i >= 0)
            {
                if(board[i][row+col-i] != player)
                {
                    flag = false;
                    break;
                }
            }
            else
            {
                flag = false;
                break;
            }
        }
        if(flag) return player;
        flag = true;
        for(int i = 0; i < size; ++i)
        {
            if(col - row + i < size && col - row + i >= 0)
            {
                if(board[i][col - row + i] != player)
                {
                    flag = false;
                    break;
                }
            }
            else
            {
                flag = false;
                break;
            }
        }
        if(flag) return player;
        else return 0;
    }
    int move(int row, int col, int player) {
        board[row][col] = player;
        return check(row, col, player);
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */


/*
26ms, 75.05%
哇！居然这么快~~~

也可以用row, col, anti, diag数组做，两个玩家就表示为++ 和 --

29ms, 41.86%
注意这里是-size才算赢！
*/
class TicTacToe {
private:
    vector<int> rows, cols;
    int diag, anti;
    int size;
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        rows.resize(n, 0);
        cols.resize(n, 0);
        diag = anti = 0;
        size = n;
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        if(player == 1){
            rows[row]++;
            if(rows[row] == size) return player;
            cols[col]++;
            if(cols[col] == size) return player;
            if(row + col == size-1) {
                diag++;
                if(diag == size) return player;
            }
            if(row == col)
            {
                anti++;
                if(anti == size) return player;
            }
        }
        else
        {
            rows[row]--;
            if(rows[row] == -size) return player;
            cols[col]--;
            if(cols[col] == -size) return player;
            if(row + col == size-1) {
                diag--;
                if(diag == -size) return player;
            }
            if(row == col)
            {
                anti--;
                if(anti == -size) return player;
            }
        }
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */






