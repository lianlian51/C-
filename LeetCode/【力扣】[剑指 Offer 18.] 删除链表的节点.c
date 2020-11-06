/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteNode(struct ListNode* head, int val){
    // cur表示遍历链表，prev表示cur的前一个节点
    struct ListNode * cur = head;
    struct ListNode * prev = NULL;
    // 寻找节点，并且标记
    while(cur->next != NULL && cur->val != val)
    {
        prev = cur;
        cur = cur->next;
    }

    // prev为空，说明是头删，那么就返回cur->next
    if(prev == NULL)
        return cur->next;

    // if(cur->val == val) 成立，则改变节点指向
    if(cur->val == val)
    {
        prev->next = cur->next;
    }
    return head;
}
