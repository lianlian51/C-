#include <iostream>

using namespace std;

// 对应内置类型
struct TrueType
{
	static bool Get()
	{
		return true;
	}
};

// 对应自定义类型
struct FalseType
{
	static bool Get()
	{
		return false;
	}
};

// 处理自定义类型
template<class T>
struct Typetraits
{
	typedef FalseType IsPODType;
};

// 内置类型
template<>
struct Typetraits<int>
{
	typedef TrueType IsPODType;
};

template<>
struct Typetraits<double>
{
	typedef TrueType IsPODType;
};

template<>
struct Typetraits<char>
{
	typedef TrueType IsPODType;
};


template <class T>
void Copy(T* dst, const T* src, size_t size)
{
	// T-->int Typetaits<int>走已经特化的模板，IsPODType是TrueType的别名
	//         Typetaits<T>::IsPODType===>typetaits<int>::IsPODType::Get()---->return true

	// T-->Date Typetaits<Date>走未特化的模板，IsPODType是FalseType的别名
	//         Typetaits<T>::IsPODType===>typetaits<Date>::IsPODType::Get()---->return false

	// 1.内置类型
	if (Typetraits<T>::IsPODType::Get())
	{
		memcpy(dst, src, sizeof(T)*size);
	 }
	else
	{
		// 2.自定义类型
		for (size_t i = 0; i < size; i++)
			dst[i] = src[i];
	 }
}

class String
{
public:
	String(const char* str = "")
	{
		if (str == nullptr)
			str = "";
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}

	String(const String& str)
		: _str(nullptr)
	{
		String temp(str._str);
		swap(_str, temp._str);
	}

	String& operator=(String s)
	{
		swap(_str, s._str);
		return *this;
	}

	~String()
	{
		if (_str)
		{
			delete[] _str;
			_str = nullptr;
		}
	}
private:
	char* _str;
};

int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	int arr2[10] = { 0 };
	Copy(arr2, arr, 10);

	String s1[] = { "1111", "2222", "3333", "4444" };
	String s2[4];
	Copy(s2, s1, 4);
	return 0;
}
