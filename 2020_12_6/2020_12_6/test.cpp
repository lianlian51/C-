#include <iostream>
using namespace std;
#include <string.h>
#if 0
// ������ģ�����
namespace test{
	template<class T, class N> // class N
	class deque
	{
	public:
		deque()
			: size(0)
		{

		}
	private:
		T arr_[N];
		size_t size;
	};
};

// ����ģ��
template<class T>
cosnt T& Max(const T& left, const T& right)
{
	return left > right ? left : right;
}

// max��������char* �Ĵ������һ������
const char* Max(const char* left, const char*  right)
{
	if (strcmp(left, right))
		return left;
	return right;
}
#endif
#if 0
// ����ģ����ػ�
template<class T>
T& Max(T& left, T& right)
{
	return left > right ? left : right;
}

template<>
char*& Max<char*>(char*& left, char*& right)
{
	if (strcmp(left, right))
		return left;
	return right;
}
#endif
#if 0
// ����ģ����ػ� const
const T& Max(const T& left,const T& right)
{
	return left > right ? left : right;
}

template<>
const char*& Max<char*>(const char*& left, cosnt char*& right)
{
	if (strcmp(left, right))
		return left;
	return right;
}

// ����ģ���ػ�����
void Test()
{
	char * s1 = "hello";
	char* s2 = "World";

	cout << Max(s1, s2) << endl;
}
#endif
// ��ģ��
#if 0
template<class T1, class T2>
class Data
{
public:

	Data()
	{
		cout << "T1, T2" << endl;
	}
private:
	T1 d1;
	T2 d2;
};

// ȫ�ػ��������еĲ������Ͷ�����
template<>
class Data<int, double>
{
public:
	Data()
	{
		cout << "int, double" << endl;
	}
private:
	int d1;
	double d2;
};


// ƫ�ػ�
template<class T1>
class Data<class T1, int>
{
public:
	Data()
	{
		cout << "T1, int" << endl;
	}
	private:
	T1 d1;
	int d2;
};

// ģ��������Ƹ��ϸ�
// ֻҪ������������ָ�����ͣ��Ǹ����ϸ��ƫ�ػ�
template<class T1, class T2>
class Data<T1*, T2*>
{
public:
	Data()
	{
		cout << "T1*, T2*" << endl;
	}
private:
	T1* d1;
	T2* d2;
};



int main()
{
	return 0;
}
#endif

// ������ȡ
struct TrueType
{
	static bool Get()
	{
		return true;
	}
};

struct FalseType
{
	static bool Get()
	{
		return false;
	}
};


template<class T>
struct TypeTraits
{
	typedef FalseType PODTYPE;
};

// ��������ģ���ػ�
template<>
struct TypeTraits<int>
{
	typedef TrueType PODTYPE;
};

template<>
struct TypeTraits<double>
{
	typedef TrueType PODTYPE;
};

template<>
struct TypeTraits<char>
{
	typedef TrueType PODTYPE;
};

class String
{
public:
	String(const char* s = "")
	{
		if (s == nullptr)
			s = "";

		_str = new char[strlen(s) + 1];
		strcpy(_str, s);
	}

	// ����漰����Դ������������ �������� ��ֵ��������ر������---three big
	String(const String& s)
		: _str(new char[strlen(s._str) + 1])
	{
		strcpy(_str, s._str);
	}

	String& operator=(const String& s)
	{
		if (this != &s)
		{
			char* temp = new char[strlen(s._str) + 1];
			strcpy(temp, s._str);
			delete[] _str;
			_str = temp;
		}
		return *this;
	}

	~String()
	{
		if (_str != nullptr)
		{
			delete[] _str;
			_str = nullptr;
		}
	}
private:
	char* _str;
};

template<class T>
void Copy(T* dst, const T* src, size_t size, TrueType)
{
	// Ч�ʸߣ����ֽڿ���
	// ǳ���������ܻ�����ڴ�й©
	// ��������
	memcpy(dst, src, size*sizeof(T));
}

template<class T>
void Copy(T* dst, const T* src, size_t size, FalseType)
{
	// Ч�ʵͣ�����һ���������
	// �Զ�������
	for (size_t i = 0; i < size; i++)
		dst[i] = src[i];
}


template < class T>
void Copy(T* dst, const T*src, size_t size)
{
	Copy(dst, src, size, TypeTraits<T>::PODTYPE());
}

int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	int _arr[sizeof(arr)/sizeof(arr[0])];
	Copy(arr, _arr, sizeof(arr)/ sizeof(arr[0]));

	String s[] = { "111", "222", "333" };
	String _s[3];
	Copy(_s, s, 3);

	return 0;
}




struct TrueType
{
	static bool Get()
	{
		return true;
	}
};


struct FalseType
{
	static bool Get()
	{
		return false;
	}
};

template<class T>
struct TypeTraits
{
	typedef FalseType PODTYPE;
};

template<>
struct TypeTraits<int>
{
	typedef TrueType PODTYPE;
};

template<>
struct TypeTraits<double>
{
	typedef TrueType PODTYPE;
};

template<>
struct TypeTraits<char>
{
	typedef TrueType PODTYPE;
};