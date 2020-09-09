/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


bool isAincludeB(struct TreeNode* A, struct TreeNode* B){
    // 对于B空的直接返回true
    if(B == NULL)
        return true;
    
    // 对于A空直接返回false
    if(A == NULL)
        return false;

    if(A->val != B->val)
        return false;
    
    // 找A和B的left和right是否也相等
    return isAincludeB(A->left, B->left) && isAincludeB(A->right, B->right);

}


bool isSubStructure(struct TreeNode *A,  struct TreeNode *B)
{
    // res记录isAincludeB的结果
    bool res = false;
    if(A != NULL && B != NULL)
    {
        // 看第一个是否相等，不相等则访问左右子树
        if(A->val == B->val) res = isAincludeB(A, B);
        if(!res) res = isSubStructure(A->left, B);
        if(!res) res = isSubStructure(A->right, B);
    }
    // 返回res
    return res;
}
