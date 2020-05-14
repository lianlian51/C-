class Solution {
public:
    int firstUniqChar(string s) {
        // 利用数组下标来标记个字符的个数
        int charCount[256] = {0};

        for(auto ch : s)
            charCount[ch]++;

        // 遍历字符串s，如果是是1 的话直接返回索引
        for(int i = 0; i < s.size(); ++i)
        {
            if(charCount[s[i]] == 1)
                return i;
        }
    return -1;
    }
};
