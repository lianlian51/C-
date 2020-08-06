class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        // 数组不能为空
        if(matrix.size() == 0)
            return false;
        // i表示行，j表示列，从最后一列开始
        int i = 0;
        int j = matrix[0].size() - 1;
        // 如果扎到target则返回true，大于target则j--，否则i++
        while( j >= 0  && i < matrix.size())
        {
            if(matrix[i][j] == target)
                return true;
            else if(matrix[i][j] > target)
                j--;
            else
                i++;
        }
        return false;
    }
};
