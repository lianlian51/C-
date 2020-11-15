#include <iostream>
using namespace std;
#include <assert.h>
class String
{
public:
	String(const char* str = "")
	{
		if (nullptr == str)
		{
			assert(false);
			return;
		}
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}

	String(const string& s)
		: _str(new char[strlen(s._str) + 1])
	{
			strcpy(_str, s._str);
	}

	String& operator=(const string& s)
	{
		if (this != &s)
		{
			char* temp = new char[strlen(s._str) + 1];
			strcpy(_str, s._str);

			delete[] _str;
			_str = temp;
		}
		return *this;
	}
	~String()
	{
		delete[] _str;
		_str = nullptr;
	}

private:
	char* _str;
};


int main()
{
	return 0;
}