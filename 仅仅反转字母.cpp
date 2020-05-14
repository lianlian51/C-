class Solution {
public:
    string reverseOnlyLetters(string S) {
        //这里用left和right标记字符串的首尾
        int left = 0;
        int right = S.size() - 1;

        while(left < right)
        {
            //寻找第一个有效字符
            while(left < right)
            {
                if(isalpha(S[left]))
                    break;
                left++;
            }

            //从后往前寻找第一个有效字符
            while(left < right)
            {
                if(isalpha(S[right]))
                    break;
                right--;
            }

            //交换
            if(left < right)
            {
                swap(S[left], S[right]);
                left++;
                right--; 
            }
        }
        return S;
    }
};
