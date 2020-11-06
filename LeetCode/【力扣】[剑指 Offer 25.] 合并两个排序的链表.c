/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    // 头结点head
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    // tail表示之后连接上的节点
    struct ListNode* tail = head;

    while(l1 != NULL && l2 != NULL)
    {
        // 小的val先放在tail后面，之后tail和链表各走一步
        if(l1->val < l2->val)
        {
            tail->next = l1;
            tail = tail->next;
            l1 = l1->next;
        }
        else 
        {
            tail->next = l2;
            tail = tail->next;
            l2 = l2->next;
        }
    }

    // 对于没有走完的链表，需要连接到tail之后
    if(l1 == NULL)
        tail->next = l2;
    else 
        tail->next = l1;

    // 返回head->next
    return head->next;
}
