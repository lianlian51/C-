/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define MAXLINE 2000

int* levelOrder(struct TreeNode* root, int* returnSize){
    returnSize[0] = 0;
    if(root == NULL) return NULL;

    int front = 0;
    int tail = 0;
    struct TreeNode* queue[MAXLINE];
    int* res = (int*)malloc(sizeof(int)*MAXLINE);
    queue[tail++] = root;
    while(front < tail)
    {
        struct TreeNode*tmp = (struct TreeNode*)malloc(sizeof(struct TreeNode)*MAXLINE);
        tmp = queue[front++];
        res[returnSize[0]++] = tmp->val;
        if(tmp->left != NULL)
            queue[tail++] = tmp->left;
        if(tmp->right != NULL)
            queue[tail++] =tmp->right;
    }
    return res;
}
