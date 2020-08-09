/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* reversePrint(struct ListNode* head, int* returnSize){
    // head为空，直接返回
    if(head == NULL)
    {
        *returnSize = 0;
        return NULL;
    }
    // C语言定义要struct
    struct ListNode* p = head;
    // num用来计算链表的长度
    int num = 0;
    while(p != NULL)
    {
        p = p->next;
        num++;
    }
    // res最后返回的数组
    int* res = (int *)malloc(sizeof(int)*num);
    p = head;
    for(int i = 0; i < num; i++)
    {
        // 反向赋值
        res[num - 1 - i] = p->val;
        p = p->next;
    }
    *returnSize = num;
    return res;
}
