/*
Author:		Cole Meyers - csm5532
Class:		CMPSC 122
Assignment: 6
File:		C:\Users\Cole Meyers\Documents\School\Penn State\CMPSC 122\projects\proj6\proj6\mystring.cpp
Purpose:	class object - overloading operators, internal and external

I certify that this program code is my work. Others may have assisted me with
planning and concepts, but the code was written solely by me.

I understand that submitting code which is totally or partially the product of
other individuals is a violation of the Academic Integrity Policy and accepted
ethical precepts. Falsified execution results are also results of improper
activities. Such violations may results in zero credit for the assignment,
reduced credit for the assignment, or course failure.
*/
#include <iostream>
#include <cstring>
#include "mystring.h"
#include <cstdlib>
using namespace std;

//Destructor
String::~String()
{
	delete[] str;
}

//Definition of default constructor "String()"
String::String()
{
	len = 1;
	str = new char[len];
	str[0] = '\0';
}

//Definition of copy constructor
String::String(const String & original)
{
	len = original.len;
	str = new char[len + 1];
	strcpy(str, original.str);
}


//Definition of parameter-initialized constructor 
String::String(const char s[])
{
	len = strlen(s);
	str = new char[len + 1];
	strcpy(str, s);
}

//Assignment overloading
String & String::operator = (const String & original)
{
	delete[] str;
	len = original.len;
	str = new char[len + 1];
	strcpy(str, original.str);
	return *this;
}


//Definition of += operator
String String::operator += (const String & original)
{
	append(original);
	return *this;
}


//Definition of [] operator
char String::operator [] (int i) const
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

//Definition of == operator - checks for equality
bool String::operator == (const String &s) const
{
	if (strcmp(str, s.str) == 0)
		return true;
	else
		return false;
}

//Definition of != operator - checks for inequality
bool String::operator != (const String &s) const
{
	if (strcmp(str, s.str) != 0)
		return true;
	else
		return false;
}

//Definition of > operator - checks for greater than condition
bool String::operator > (const String &s) const
{
	if (strcmp(str, s.str) > 0)
		return true;
	else
		return false;
}


//Definition of < operator - checks for less than condition
bool String::operator < (const String &s) const
{
	if (strcmp(str, s.str) < 0)
		return true;
	else
		return false;
}

//Definition of print method - invokes <cstring> method printf()
void String::print() const
{
	printf(str);
}

//Definition of overloaded print function
void String::print(ostream & out) const
{
	out << str;
}

//Definition of << for String class
std::ostream & operator << (std::ostream & out, const String & s)
{
	s.print(cout);
	return out;
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

