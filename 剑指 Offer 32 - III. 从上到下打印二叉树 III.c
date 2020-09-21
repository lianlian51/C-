/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
 typedef struct queue{
    struct TreeNode *data[1009];
    int head;
    int tail;
}QUEUE,*PQUEUE;
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    //判断树是否为空
    if (!root)
    {
        *returnSize = 0;
        return NULL;
    }
    //将根节点入队
     //将根节点入队
    QUEUE q;
    q.head = 0;
    q.tail = 1;
    q.data[0] = root;

    int col=0;//记录行数
    int num;//记录每行个数
    int** result = (int **)malloc(sizeof(int*)*1009);
    result[col]=(int *)malloc(sizeof(int)*1009);
    returnColumnSizes[0]=(int *)malloc(sizeof(int)*1009);
    while(q.tail!=q.head){
        num=0;
        int end=q.tail;//记录下次队列的队尾
        result=(int **)realloc(result,sizeof(int*)*(col+1));
        result[col]=(int *)malloc(sizeof(int));
        //队列出完
        while(q.tail!=q.head){
            result[col]=(int *)realloc(result[col],sizeof(int)*(num+1));
            result[col][num]=q.data[q.head]->val;
            if(q.data[q.head]->left){
                q.data[end++]=q.data[q.head]->left;
            }
            if(q.data[q.head]->right){
                q.data[end++]=q.data[q.head]->right;
            }
            q.head++;
            num++;
        }
        //换位
        if(col%2){
            int swap;
            int no=0;
            for(int x=num-1;x>=num/2;x--){
                swap=result[col][x];
                result[col][x]=result[col][no];
                result[col][no++]=swap;
            }
        }
        //给返回的记录数组大小的数组分配空间
        returnColumnSizes[0]=(int *)realloc(*returnColumnSizes,sizeof(int)*(col+1));
        returnColumnSizes[0][col]=num;
        q.head=q.tail;
        q.tail=end;
        col++;
        
    }
    *returnSize=col;
    return result;
}
