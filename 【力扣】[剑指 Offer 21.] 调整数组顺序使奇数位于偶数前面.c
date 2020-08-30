/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* exchange(int* nums, int numsSize, int* returnSize){
    // left表示第一个元素的下标，right表示最后一个元素的下标
    int left = 0;
    int right = numsSize - 1;

    // 保证不越界
    while(left < right)
    {
        // 找第一个是偶数，并标记
        if((nums[left] % 2) == 1)
        {
            left++;
            continue;
        }

        // 从后往前找第一个奇数
        if((nums[right] % 2) == 0)
        {
            right--;
            continue;
        }
        
        // 交换
        if((nums[left] % 2 == 0) && (nums[right] % 2) == 1)
        {
            int temp = nums[left];
            nums[left] = nums[right];
            nums[right] = temp;

            left++;
            right--;
        }
    }
    
    *returnSize = numsSize;
    return nums;
}
