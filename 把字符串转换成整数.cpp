class Solution {
public:
    int StrToInt(string str) {
        // ret最终返回值
        int ret = 0;
        // flag 控制正负
        int flag = 1;
        // 字符串长度
        int temp = str.size();
        if(temp < 1)
            return 0;
        // 第一个字符是'-'，则flag = -1
        if(str[0] == '-')
        {
            flag = -flag;
        }
        
        // 如果第一个字符是‘-’，则从第二个字符开始遍历
        int i = (str[0] == '-' || str[0] == '+') ? 1 : 0;
        for(i; i < temp; i++)
        {
            // 字符是数字直接操作，否则返回0
            if(str[i] >= '0' && str[i] <= '9')
                ret = ret * 10 + (str[i] -'0');
            else
                return 0;
        }
        // 这里返回ret*flag
        return ret * flag;
    }
};
