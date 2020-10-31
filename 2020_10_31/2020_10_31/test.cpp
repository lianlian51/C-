typedef struct ArcNode{

	int adjvex; //该弧所指向的顶点的位置

	char info; //权

	struct ArcNode *nextarc; //指向下一条弧的指针

}ArcNode;

typedef struct VNode{

	char data; //顶点信息

	ArcNode *firstarc; //指向第一条依附该顶点的弧的指针

}VNode;




#include<stdio.h>
#include<string.h>
int main()
{
	char c, s[20], *p;
	int a = 1234, *i;
	float f = 3.141592653589;
	double x = 0.12345678987654321;
	p = "How do you do";
	strcpy(s, "Hello, Comrade");
	*i = 12;
	c = '\x41';
	printf("a=%d\n", a);     /*结果输出十进制整数a=1234*/
	printf("a=%6d\n", a);    /*结果输出6位十进制数a=  1234*/
	printf("a=%06d\n", a);   /*结果输出6位十进制数a=001234*/
	printf("a=%2d\n", a);    /*a超过2位, 按实际值输出a=1234*/
	printf("*i=%4d\n", *i);  /*输出4位十进制整数*i=  12*/
	printf("*i=%-4d\n", *i); /*输出左对齐4位十进制整数*i=12*/
	printf("i=%p\n", i);     /*输出地址i=06E4*/

	printf("f=%f\n", f);     /*输出浮点数f=3.141593*/
	printf("f=6.4f\n", f);   /*输出6位其中小数点后4位的浮点数f=3.1416*/
	printf("x=%lf\n", x);    /*输出长浮点数x=0.123457*/
	printf("x=%18.16lf\n", x);/*输出18位其中小数点后16位的长浮点数x=0.1234567898765432*/

	printf("c=%c\n", c);     /*输出字符c=A*/
	printf("c=%x\n", c);     /*输出字符的ASCII码值c=41*/
	printf("s[]=%s\n", s);   /*输出数组字符串s[]=Hello, Comrade*/
	printf("s[]=%6.9s\n", s);/*输出最多9个字符的字符串s[]=Hello,Co*/
	printf("s=%p\n", s);     /*输出数组字符串首字符地址s=FFBE*/
	printf("*p=%s\n", p);    /* 输出指针字符串p=How do you do*/
	printf("p=%p\n", p);     /*输出指针的值p=0194*/
	return 0;
}