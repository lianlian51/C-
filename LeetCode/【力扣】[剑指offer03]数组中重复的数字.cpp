class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        // 先对数组进行排序
        sort(nums.begin(), nums.end());

        // 然后找相邻的数字是否相同，相同即返回，
        // 循环至结束，没有找到的话就返回-1
        for(int i = 0; i < nums.size(); ++i)
        {
            int j = i + 1;
            if(nums[i] == nums[j])
                return nums[i];
        }
        return -1;
    }
};
