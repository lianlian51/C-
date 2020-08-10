/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize){
    // 退出递归的条件
    if(preorderSize == 0)
        return NULL;
    // 将第一个节点赋值过去
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = preorder[0];
    // 在中序遍历中找到val，然后标记起来
    int k = 0;
    for(k = 0; k < inorderSize; ++k)
    {
        if(inorder[k] == preorder[0])
            break;
    }
    // 对左右子树进行递归操作，这里需要注意的是给的地址以及数组的大小
    node->left = buildTree(&preorder[1], k, &inorder[0], k);
    node->right = buildTree(&preorder[k + 1], preorderSize - 1 - k, &inorder[k + 1], inorderSize - 1 - k);
    return node;
}
