class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // 第一种方法：优先级队列
        // // 建立大堆
        // priority_queue<int> p(nums.begin(), nums.end());
        // // 出前k-1个元素
        // for(int i = k - 1; i > 0; --i)
        //     p.pop(); 

        // // 最后返回堆顶元素
        // return p.top();

        // // 2.排序（升序）
        // sort(nums.begin(), nums.end());
        // return nums[nums.size() - k];     

        // 3.排序（降序）   
        sort(nums.begin(), nums.end(), greater<int>());  // greater<int> () 记得加括号
        return nums[k - 1];     
    }
};
