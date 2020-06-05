class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        // 先进行排序
        sort(numbers.begin(), numbers.end());
        
        // 记录最中间的数字（因为如果存在这个数字的话，那么这个数字一定会在中间出现）
        int mid = numbers[numbers.size() / 2];
        // 记录mid出现的次数
        int count =0;
        for(int i = 0; i < numbers.size(); i++)
        {
            if(mid == numbers[i])
                count++;
        }
        // 最后看count是否大于一半
        return count > numbers.size()/2 ? mid : 0;
    }
};
