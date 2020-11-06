typedef struct {
    // 两个栈，长度，top，
    int len;
    int top1;
    int top2;
    int *s1;
    int *s2;
} CQueue;


CQueue* cQueueCreate() {
    // 队列开辟，初始化，两个栈开辟空间
    CQueue* q = malloc(sizeof(CQueue));
    q->len =10000;
    q->top1 = -1;
    q->top2 = -1;
    q->s1 = malloc(sizeof(int)*q->len);
    q->s2 = malloc(sizeof(int)*q->len);

    // 返回
    return q;
}

void cQueueAppendTail(CQueue* obj, int value) {
    // 如果top1的栈为-1，那就直接将s2所有的元素倾倒s1中，在给++top1的位置赋值value
    if(obj->top1 == -1)
    {
        while(obj->top2 != -1)
            obj->s1[++(obj->top1)] = obj->s2[obj->top2--];
    }
    obj->s1[++(obj->top1)] = value;
}

int cQueueDeleteHead(CQueue* obj) {
    // 如果top2的为-1，那就直接将s1的所有元素倾倒s2中，在对top2--
    if(obj->top2 == -1)
    {
        while(obj->top1 != -1)
            obj->s2[++(obj->top2)] = obj->s1[obj->top1--];
    }
    return obj->top2 == -1 ? -1 : obj->s2[obj->top2--];
}

void cQueueFree(CQueue* obj) {
    // 释放所有的空间
    free(obj->s1);
    free(obj->s2);
    free(obj);
}

/**
 * Your CQueue struct will be instantiated and called as such:
 * CQueue* obj = cQueueCreate();
 * cQueueAppendTail(obj, value);
 
 * int param_2 = cQueueDeleteHead(obj);
 
 * cQueueFree(obj);
*/
