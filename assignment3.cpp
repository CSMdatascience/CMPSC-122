#include "mystring.h"
#include <iostream>
#include <cstring>
using namespace std;


//Definition of default constructor "String()"
String::String()
{
	str[0] = '\0';
	len = 0;
}

//Definition of assignment method - assigns a character array to str
void String::assign(const char s[])
{
	int i = 0;
	for (i; s[i] != '\0'; i++)
		str[i] = s[i];
	str[i] = '\0';
	len = i;
}


//Definition of append method - concatenates input string to str
void String::append(const String &s)
{
	int i = 0;
	for (i; s.str[i] != '\0';)
	{
		str[len] = s.str[i];
		len++; i++;
	}
	str[len] = '\0';

}

//Definition of comparison method - invokes <cstring> method strcmp()
int String::compare_to(const String &s) const
{
	return strcmp(str, s.str);
}

//Definition of print method - invokes <cstring> method printf()
void String::print() const
{
	printf(str);
}

//Definition of length method - returns len variable
int String::length() const
{
	return len;
}

//Definition of element method - returns specified element of str[]
char String::element(int i) const
{
	if (i > len)
	{
		cout << "Error - index out of range" << endl;
		return '\0';
	}
	else
	{
		return str[i];
	}
}
