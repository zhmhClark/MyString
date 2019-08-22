#pragma once
#include<iostream>
#include<cstring>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;
class MyString
{
	friend ostream& operator<<(ostream&, const MyString&);
private:
	char* s;
	int length;
	void setMyString(const char* s);
public:
	MyString(const char* = 0);
	MyString(const MyString&);
	~MyString();
	int getLength() const { return length; };
	//重载常用运算符
	const MyString& operator=(const MyString&);
	const MyString& operator+=(const MyString&);
	bool operator!() const { return length == 0; }
	bool operator==(const MyString& right) const { return !strcmp(s,right.s); }
	bool operator<(const MyString& right) const { return strcmp(s, right.s)<0; }
	char& operator[](int index) { return s[index]; }
	//用已重载的运算符重载相关运算符
	bool operator!=(const MyString& right) const { return !( *this == right ); }
	bool operator>(const MyString& right) const { return  right > *this ; }
	bool operator<=(const MyString& right) const { return !( *this > right ); }
	bool operator>=(const MyString& right) const { return !( *this < right ); }
	//新增
	void add(char c);
};    

