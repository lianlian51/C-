/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* mirrorTree(struct TreeNode* root){
    // 如果root为空，那返回空
    if(root == NULL)
        return NULL;

    // 将左右子树交换
    struct TreeNode*temp = root->left;
    root->left = root->right;
    root->right = temp;

    // 左右子树的交换
    root->left = mirrorTree(root->left);
    root->right = mirrorTree(root->right);

    return root;
}
