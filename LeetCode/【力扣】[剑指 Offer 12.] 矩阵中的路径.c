bool _exist(char** board,int boardSize,int* boardColSize,char* word,int row,int col,int len)
{
    // 对边界条件进行判断，不是矩阵最后一个字母也返回false
    if(row < 0 || col < 0 || row >= boardSize ||col >= *boardColSize || board[row][col] != word[len] )
        return false;

    // 判断是否完成路径，完成路径说明矩阵中还存在满足条件的路径
    // len 每次++ 直到相等的时候返回true，否则返回false
    if(strlen(word) - 1 == len)  
        return true;
    // 将当前的位置设置为非字母，使得递归时不会出现再次查找的情况
    char tmp = board[row][col];
    board[row][col] = '*';
    // 从当前位置的上下左右递归判断四个方向是否存在满足路径的下一个节点
    // 不存在的话返回false，有的话返回true
    bool res = (_exist(board, boardSize, boardColSize, word, row, col + 1, len + 1) ||
               _exist(board, boardSize, boardColSize, word, row, col - 1, len + 1) ||
               _exist(board, boardSize, boardColSize, word, row + 1, col, len + 1) ||
               _exist(board, boardSize, boardColSize, word, row - 1, col, len + 1) );
    // 将该位置还原
    board[row][col] = tmp;
    return res;
}

bool exist(char** board, int boardSize, int* boardColSize, char* word){
    for(int i = 0; i < boardSize; i++)
    {
        for(int j = 0; j < *boardColSize; j++)
        {
            // 对矩阵中的所有字母开始遍历，然后下一个字母如果存在的话，那么一定返回true，否则返回false，知道返回true位置，循环结束没有返回true的话，直接返回false
            if(_exist(board, boardSize, boardColSize, word, i, j, 0))
                return true;
        }
    }
    return false;
}
