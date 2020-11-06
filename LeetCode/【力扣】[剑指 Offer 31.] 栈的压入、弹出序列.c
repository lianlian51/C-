bool validateStackSequences(int* pushed, int pushedSize, int* popped, int poppedSize){
    // stack用来存储压栈数字
    int stack[pushedSize + 1];
    // stack_top表示栈顶
    int stack_top = -1;
    // push_id入栈id，pop_id出栈id
    int push_id = 0, pop_id = 0;
    for(push_id; push_id < pushedSize; push_id++)
    {
        // 入栈
        stack[++stack_top] = pushed[push_id];
        // 判断是否要出栈：对于相等的数字直接出栈pop_id++，stack_top--
        while(stack_top + 1 > 0 && pop_id < poppedSize && stack[stack_top] == popped[pop_id])
        {
            stack_top--;
            pop_id++;
        }
    }
    // 当pop_id==poppedSize则表示栈空，返回true
    if(pop_id == poppedSize)
        return true;
    return false;
}
