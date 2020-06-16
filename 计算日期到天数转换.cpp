#include <iostream>
using namespace std;

// 判断是不是闰年
bool boolyear(int _year)
{
    if(_year % 400 == 0|| (_year % 4 == 0 && _year % 100 != 0))
        return true;
    return false;
}

int main()
{
    int year, month, day;
    // 十二个月的天数，只有二月要判断是否闰年+1
    int arr[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    // 算出所有的月的和
    int sum = 0;
    while(cin >> year >> month >> day)
    {
        // 因为多组数据，所以每次置为0
        sum = 0;
        // 如果是闰年，下面肯定arr[1]肯定会是29，所以要在这里把他置为28
        // 在判断是不是闰年，是否要在+1
        arr[1] = 28;
        if(boolyear(year))
            arr[1] = 29;
        // 将前month - 1个月的天数加起来
        for(int i = 0; i < month - 1; i++)
            sum += arr[i];
        // 加最后一个月
        sum += day;
        // 打印
        cout << sum << endl;
    }
    return 0;
}
