#include <iostream>
#include <time.h>
#include<math.h>
#define Bsize 3
#define Psize 12
#include<string>
using namespace std;
int QString[Psize];
int Num = 0;
struct pageInfor
{
	int content;
	int timer;
};

class YZ_replace
{
public:
	YZ_replace();
	~YZ_replace();
	int findSpace();
	int findExist(int curpage);
	int findReplace();
	void FIFO();
	void OPT();
	void BlockClear();
	void initia1(int string[]);
	pageInfor *block;
	pageInfor *page;
	int memory_state[Bsize][Psize];
	int s;
private:
};
void P_String(int QString[])
{
	int i;
	srand((unsigned)time(NULL));
	for (i = 0; i<Psize; i++)
	{
		QString[i] = rand() * 9 / RAND_MAX + 1;
	}
	cout << "页面走向：";
	for (i = 0; i<Psize; i++)
	{
		cout << QString[i] << " ";
	}
	cout << endl;
}
YZ_replace::YZ_replace()
{
	s = 0;
	block = new pageInfor[Bsize];
	for (int i = 0; i<Bsize; i++)
	{
		block[i].content = -1;
		block[i].timer = 0;
	}
}
void YZ_replace::initia1(int QString[])
{
	int j;
	page = new pageInfor[Psize];
	for (int i = 0; i<Psize; i++)
	{
		page[i].content = QString[i];
		page[i].timer = 0;
	}
	for (int i = 0; i<Psize; i++)
	for (j = 0; j<Bsize; j++)
		memory_state[j][i] = 0;
}
YZ_replace::~YZ_replace()
{
	s = 0;
}

int YZ_replace::findSpace()
{
	for (int i = 0; i<Bsize; i++)
	if (block[i].content == -1)
		return i;
	return -1;
}
int YZ_replace::findExist(int curpage)
{
	for (int i = 0; i<Bsize; i++)
	if (block[i].content == page[curpage].content)
		return i;
	return -1;
}

int YZ_replace::findReplace()
{
	int pos = 0;
	for (int i = 0; i<Bsize; i++)
	if (block[i].timer >= block[pos].timer)
		pos = i;
	return pos;
}

void YZ_replace::FIFO()
{
	int exist, space, position;
	for (int i = 0; i<Psize; i++)
	{
		exist = findExist(i);
		if (exist != -1)
		{
			for (int b = 0; b<Bsize; b++)
			{
				memory_state[b][i] = memory_state[b][i - 1];
			}
			s++;
		}
		else
		{
			space = findSpace();
			if (space != -1)
			{
				for (int b = 0; b<Bsize; b++)
				{
					memory_state[b][i] = memory_state[b][i - 1];
				}
				block[space] = page[i];
				memory_state[space][i] = block[space].content;
			}
			else
			{
				for (int b = 0; b<Bsize; b++)
				{
					memory_state[b][i] = memory_state[b][i - 1];
				}
				position = findReplace();
				block[position] = page[i];
				memory_state[position][i] = block[position].content;
			}
		}
		for (int j = 0; j<Bsize; j++)
			block[j].timer++;
	}
}

void YZ_replace::BlockClear()
{
	for (int i = 0; i<Bsize; i++)
	{
		block[i].content = -1;
		block[i].timer = 0;
	}
}

typedef struct page
{
	int num;
	int time;
}Page;

Page b[Bsize];
Page call[Bsize];
int c[Bsize][Psize];
int queue[100];
int K;

void InitL(Page *b, int c[Bsize][Psize])
{
	int i, j;
	for (i = 0; i<Bsize; i++)
	{
		b[i].num = -1;
		b[i].time = Psize - i - 1;
	}
	for (i = 0; i<Bsize; i++)
	for (j = 0; j<Psize; j++)
		c[i][j] = -1;
}
int GetMax(Page *b)
{
	int i;
	int max = -1;
	int tag = 0;
	for (i = 0; i<Bsize; i++)
	{
		if (b[i].time>max)
		{
			max = b[i].time;
			tag = i;
		}
	}
	return tag;
}
int Equation(int fold, Page *b)
{
	int i;
	for (i = 0; i<Bsize; i++)
	{
		if (fold == b[i].num)
			return i;
	}
	return -1;
}
void Lru(int fold, Page *b)
{
	int i;
	int val;
	val = Equation(fold, b);
	if (val >= 0)
	{
		b[val].time = 0;
		for (i = 0; i<Bsize; i++)
		if (i != val)
			b[i].time++;
	}
	else
	{
		queue[++K] = fold;
		val = GetMax(b);
		b[val].num = fold;
		b[val].time = 0;
		for (i = 0; i<Bsize; i++)
		if (i != val)
			b[i].time++;
	}
}

void YZ_replace::OPT()
{
	int exist, space, position;
	for (int i = 0; i<Psize; i++)
	{
		exist = findExist(i);
		if (exist != -1)
		{
			for (int b = 0; b<Bsize; b++)
			{
				memory_state[b][i] = memory_state[b][i - 1];
			}
			s++;
		}
		else
		{
			space = findSpace();
			if (space != -1)
			{
				for (int b = 0; b<Bsize; b++)
				{
					memory_state[b][i] = memory_state[b][i - 1];
				}
				block[space] = page[i];
				memory_state[space][i] = block[space].content;
			}
			else
			{
				for (int k = 0; k<Bsize; k++)
				{
					memory_state[k][i] = memory_state[k][i - 1];
					for (int j = i; j<Psize; j++)
					{
						if (block[k].content != page[j].content)
						{
							block[k].timer = 1000;
						}
						else
						{
							block[k].timer = j; break;
						}
					}
				}
				position = findReplace();
				block[position] = page[i];
				memory_state[position][i] = block[position].content;
			}
		}
	}
}

int decide(string str)
{
	int i;
	for (i = 0; i<str.size(); i++)
	{
		if (str[i]<'0' || str[i]>'9')
		{
			return 0;
			break;
		}
	}
	return i;
}
int trans(string str)
{
	int sum = 0;
	for (int i = 0; i<str.size(); i++)
		sum = sum + (str[i] - '0')*pow(10, str.size() - i - 1);
	return sum;
}

int put()
{
	int a, d;
	string str;
	cin >> str;
	a = decide(str);
	while (a == 0)
	{
		cout << "输入错误,请重新输入！" << endl;
		cin >> str;
		a = decide(str);
	}
	d = trans(str);
	return d;
}
void Put()
{
	cout << "请选择产生页面的方法 a:随机产生  b:输入产生" << endl;
	cout << "您选择的菜单是:";
	char F;
	cin >> F;
	while (F != 'a'&&F != 'b')
	{
		cout << "输入错误，请重新输入:";
		cin >> F;
	}
	if (F == 'a')
		P_String(QString);
	if (F == 'b')
	{
		cout << "请输入各页面号:" << endl;
		for (int i = 0; i<Psize; i++)
		{
			QString[i] = put();
		}
	}
	cout << endl;
	cout << "|---------------------------------------------------------------|" << endl;
}
void main()
{
	cout << "|-----------------------页 面 置 换 算 法-----------------------|" << endl;
	cout << "|---------------------------------------------------------------|" << endl;
	int t = 1;
	while (t)
	{
		Put();
		YZ_replace test1;
		YZ_replace test3;
		char select;
		do{
			cout << "请选择要应用的算法:<1>FIFO算法  <2>LRU算法  <3>OPT算法  <0>退出" << endl;
			int p, q;
			cout << "请您输入菜单号:";
			cin >> select;
			while (select != '0'&&select != '1'&&select != '2'&&select != '3')
			{
				cout << "您的输入无效,请重新输入:" << endl;
				cin >> select;
			}
			if (select == '0')
			{
				cout << "您选择的是菜单<0>" << endl;
				cout << "完成退出." << endl;
				t = 0;
			}

			if (select == '1')
			{
				cout << "您选择的是菜单<1>" << endl;
				cout << "FIFO算法状态:" << endl;
				test1.initia1(QString);
				test1.FIFO();
				test1.BlockClear();
				cout << "-------------------------------------------" << endl;
				for (p = 0; p<Bsize; p++)
				{
					for (q = 0; q<Psize; q++)
						cout << test1.memory_state[p][q] << " ";
					cout << endl;
				}
				cout << "-------------------------------------------" << endl;
				cout << "命中率:" << test1.s << "/" << Psize << endl;
				test1.~YZ_replace();
				cout << endl;
			}
			if (select == '2')
			{
				int i, j;
				K = -1;
				InitL(b, c);
				for (i = 0; i<Psize; i++)
				{
					Lru(QString[i], b);
					c[0][i] = QString[i];
					for (j = 0; j<Bsize; j++)
						c[j][i] = b[j].num;
				}
				cout << "您选择的是菜单<2>" << endl;
				cout << "LRU算法状态:" << endl;
				cout << "------------------------------------------" << endl;
				for (i = 0; i<Bsize; i++)
				{
					for (j = 0; j<Psize; j++)
					{
						if (c[i][j] == -1)
							cout << " 0";
						else
							cout << " " << c[i][j];
					}
					cout << " " << endl;
				}
				cout << "------------------------------------------" << endl;
				cout << "命中率:" << (Psize - (K + 1)) << "/" << Psize;
				cout << '\t';
				cout << endl;
			}
			if (select == '3')
			{
				cout << "您选择的是菜单<3>" << endl;
				cout << "OPT算法状态:" << endl;
				test3.initia1(QString);
				test3.OPT();
				test3.BlockClear();
				cout << "------------------------------------------" << endl;
				for (p = 0; p<Bsize; p++)
				{
					for (q = 0; q<Psize; q++)
						cout << test3.memory_state[p][q] << " ";
					cout << endl;
				}
				cout << "------------------------------------------" << endl;
				cout << "命中率:" << test3.s << "/" << Psize << endl;
				test3.~YZ_replace();
				cout << endl;
			}
		} while (select == '1' || select == '2' || select == '3');
	}
}