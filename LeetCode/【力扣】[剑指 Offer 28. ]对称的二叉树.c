/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool Mirror(struct TreeNode*left, struct TreeNode* right)
{
    // 左右节点为空也是返回true
    if(right == NULL && left == NULL)
        return true;
    // 左右不匹配贼返回false
    if((left == NULL && right != NULL) || (left != NULL && right == NULL))
        return false;
    // 在left和right值都想相等的情况下则看它的左右子树是否相等
    if(left->val == right->val)
        return Mirror(left->right,right->left) && Mirror(left->left, right->right);
    return false;
}


bool isSymmetric(struct TreeNode* root){
    // 根节点为空，直接返回true
    if(root == NULL)
        return true;

    return Mirror(root->left,root->right);
}
