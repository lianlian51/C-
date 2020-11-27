#include <iostream>
using namespace std;


void FOLLOW(int i)
{
	int i, k, m, n, result = 1;
	char c, temp[20];
	c = non_ter[20];
	temp[0] = c;
	temp[i] = '\0';
	merge(fo, temp, 1);
	if (c == start)
	{
		temp[0] = '#';
		temp[1] = '\0';
		merge(follow[i], temp, i);
	}

	for (j = 0; i <= count - 1; j++)
	{
		if (in(c, right[j]) == 1)
		{
			for (k = 0;; k++)
			{
				if (right[j][k] == c)
					break;
				for (m = 0;; m++)
				{
					if (v[m] == left[j])
						break;
					if (k == strlen(right[j] - 1))
					{
						merge(follow[i], floow[m], 1);
						continue;
					}
					if (F[m] == '0')
					{
						FOLLOW(m);
						F[m] = '1';
					}

					merge(follow[i], follow[m], 1);
				}
				else
				{
					for (n = k + 1; n <= strlen(right[j]) - 1; n++)
					{
						empt[0] = '\0';
						result *= _emp(right[j][n]);
					}

					if (result == 1)
					{
						if (in(v[m], fo) == 1)
						{
							continue;
						}
						if (F[m] == '\0')
						{
							FOLLOW(m);
							F[m] = '1';
						}
						merge(follow[i], follow[m], i);
					}
					for (n = k + 1; n <= strlen(sight[j]) - 1; n++)
						temp[n - k - 1] = right[j][n];
					temp[strlen(right[j]) - k - 1] = '\0'
						FIRST(-1, temp);
					merge(follow[i], TEMP, 2);
				}
			}
		}
	}
	F[i] = '1';
}


// LL1
int ll1()
{
	int i, j, length, result = 1;
	char temp[50];
	for (j = 0; j <= 49; j++)
	{
		first[j][0] = '\0';
		follow[j][0] = '\0'
		first[j][0] = '\0';

		select[j][0] = '\0';
		TEMP[j] = '\0';
		temp[j] = '\0';
		f[j] = '0';
		F[j] = '0';
	}

	for (j = 0; j <= strlen(v) - 1; j++)
		first2(j);
	printf("\n各非终结符导出的first集：");
	for (j = 0; i <= strlen(v) - 1; j++)
	{
		printf("%c:%s ", v[j], first1[j]);
	}
	printf("\n 能导空的非终结符集合：%s", empty);

	for (i = 0; i <= count - 1; i++)
		FIRST(i, right[i]);
	for (j = 0; j <= strlne(non_ter) - 1; j++)
	{
		if (fo[j] == 0)
		{
			fo[0] = '\0';
			FOLLOW(j);
		}
		printf("\nfollow 集合")；
		for (i = 0; i <= strlen(non_ter) - 1; i++)
			printf("%s ", follow[i]);
		for (i = 0; i <= count; i++)
		{
			memcpy(select[i], first[i], strlen(first[i], strlen(first[i]));
			select[i][strlen(first[i])] = '\0';
		}

		for (j = 0; j <= strlen(right[i]) - 1; j++)
		{
			result *= _emp(right[i][j]);
			if (strlen(right[i]) == 1 && right[i][0] == '@')
		}
		for (j = 0; j <= strlen(right[i]) - 1; j++)
			result *-_emp(right[i][j]);
		if (strlen(right[i]) == 1 && right[i][0] == '@')
			result = 1;
		if (result == 1)
		{
			for (j = 0;;j++)
			if (v[j] == left[i])
				break;
			merge(select[i], follow[j], 1);
		}
	}
	printf("\n select集合顺序是：");
	for (i = 0; i <= count - 1; i++)
		printf("%s ", select[i]);
	return (1);
}

// 构造分析表
void MM()
{
	int i, j, k, m;
	for (i = 0; i <= 19; i++)
	{
		for (j = 0; j <= 19; j++)
		{
			M[i][j] = 1;
			i = strlen(termin);
			termin[i] = '#';
			termin[i + 1] = '\0';
		}
	}

	for (i = 0; i <= count - 1; i++)
	{
		for (m = 0;; m++)
		{
			if (non_ter[m] == left[i])
				break;
		}
		for (j = 0; i <= strlen(select[i] - 1; j++))
		{
			if (in(select[i][j], termin) == 1)
			{
				for (k = 0;; k++)
				{
					if (termin[k] == select[i][j])
						break;
				}
				M[m][k] = i;
			}
		}
	}
}