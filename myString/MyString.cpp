   #include "MyString.h"

void MyString::setMyString(const char* str)
{
	if (str == NULL)
	{
		s = NULL;
		length = 0;
	}
	else
	{
		length = strlen(s);
		s = new char[length + 1];
		strcpy(s, str);
	}
}

MyString::MyString(const char*str)
{
	if (str == NULL)
	{
		s = NULL;
		length = 0;
	}
	else
	{
		length = strlen(s);
		s = new char[length + 1];
		strcpy(s, str);
	}
}

MyString::MyString(const MyString& copy)
{
	if (copy.length == NULL)
	{
		s = NULL;
		length = 0;
	}
	else
	{
		length = copy.length;
		s = new char[length + 1];
		strcpy(s, copy.s);
	}
}

MyString::~MyString()
{
	if (s) delete[] s;
}

const MyString& MyString::operator=(const MyString& right)
{
	if (&right != this)
	{
		delete[] s;
		length = right.length;
		setMyString(right.s);
	}

	return *this;
}

const MyString& MyString::operator+=(const MyString& right)
{
	char* temp = s;
	length += right.length;
	s = new char[length + 1];
	strcpy(s, temp);
	strcat(s, right.s);
	delete[] temp;;
	return *this;
}

ostream& operator<<(ostream& out, const MyString& str)
{
	if (str.s) out << str.s;
	return out;
}
