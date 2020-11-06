class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        // 如果长度不相等的话，那就直接返回false
        if(pushV.size() != popV.size())
            return false;
        
        // index，outdex访问pushV，popV
        size_t index = 0;
        size_t outdex = 0;
        
        stack<int> s;
        while(outdex < popV.size())
        {
            // 这相当于一个判断，判断栈顶元素是否和弹栈序列相等
            // 不相等执行插入操作
            // 相等执行出栈操作
            while(s.empty() || s.top() != popV[outdex])
            {
                // 若是index已经越界，在进行插入的话就直接返回false
                if(index < pushV.size())
                    s.push(pushV[index++]);
                else
                    return false;
            }
            s.pop();
            outdex++;
        }
        return true;
    }

};
