/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){
	// 对空链表就直接返回
    if(head == NULL)
        return head;
    // cur遍历链表
    struct ListNode* cur = head->next;
    head->next = NULL;

    while(cur)
    {
    	// 用next标记cur的下一个，保证可以找到
        struct ListNode* next = cur->next;

        cur->next = head;
        head = cur;
        cur = next;
    }
	// 返回
    return head;
}
