#include "MyString.h"
#define _CRT_SECURE_NO_WARNINGS

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
		length = strlen(str);
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
	delete[] temp;
	return *this;
}

void MyString::add(char c)
{
	char cStr[2] = { c,'\0' };
	char* temp = s;
	char* newS = new char[length + 2];
	strcpy(newS, cStr);
	strcat(newS, s);
	s = newS;
	delete[] temp;
}

ostream& operator<<(ostream& out, const MyString& str)
{
	if (str.s) out << str.s;
	return out;
}
