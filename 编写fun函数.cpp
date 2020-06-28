#include <stdio.h> 
#include <math.h>
double fun(double x)
{
	// s0代表前一个数字，s2表示后一个
	// p来表示每个项的上面的部分，sum表示前n项和
	// t用来表示那个表达式下面的阶乘 
	double s1 = 1.0, p = 1.0, sum = 0.0;
	double s0, t = 1.0;
	int n = 1;
	// do while 先循环一次在判断 
	do{
		// 将后一个给前一个 
		s0 = s1;
		sum += s0;
		// 阶乘：每次*n，n后面每次++ 
		t *= n;
		p *= (0.5 - n + 1)*x;
		s1 = p / t;
		n++;
	} while (fabs(s1 - s0) >= 1e-6); // fabs求绝对值，后面那个就是0.000001 
	return sum;
}

int main()
{
	double x = 0.21;
	double y = fun(0.21);
	printf("%f\n", y);
}

