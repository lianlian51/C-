class Parenthesis {
public:
    bool chkParenthesis(string A, int n) {
        // write code here
        // 栈解决
        stack<char> s;
        // 遍历字符串A
        for(int i = 0; i < n; i++)
        {
            // 左括号入栈
            if(A[i] == '(')
                s.push(A[i]);
            else if(A[i] == ')')
            {
                // 判断为空的话不匹配，则直接出栈
                if(s.empty())
                    return false;
                // 栈顶是左括号直接出栈
                if(s.top() == '(')
                    s.pop();
                else 
                    // 其他直接入栈
                    s.push(A[i]);
            }
            else
                // 规避字符
                return false;
        }
        // 最后如果栈为空的话，就直接返回true，反之则不
        if(s.empty())
            return true;
        return false;
    }
};
