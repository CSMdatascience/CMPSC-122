/*
Author:		Cole Meyers - csm5532
Class:		CMPSC 122
Assignment: 4
File:		C:\Users\Cole Meyers\Documents\School\Penn State\CMPSC 122\projects\proj4\proj4\mystring.cpp
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
using namespace std;


//Definition of default constructor "String()"
String::String()
{
	str[0] = '\0';
	len = 0;
}

//Definition of parameter-initialized constructor 
String::String(const char s[])
{
	int i = 0;
	for (i; s[i] != '\0'; i++)
		str[i] = s[i];
	str[i] = '\0';
	len = i;

}

//Definition of += operator
String String::operator += (const String &s)
{
	int i = 0;
	for (i; s.str[i] != '\0';)
	{
		str[len] = s.str[i];
		len++; i++;
	}
	str[len] = '\0';
	return str;
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
void String::print (std::ostream & out) const
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

/* Sample execution of test driver:

Enter a value for str2 (no spaces): world

Enter a value for str3 (no spaces): whatup
Initial values:
str1 holds "hello" (length = 5)
str2 holds "world" (length = 5)
str3 holds "whatup" (length = 6)

Enter which element of str1 to display (an integer for the subscription): 0
Element #0 of str1 is 'h'

Enter which element of str2 to display (an integer for the subscription): 1
Element #1 of str2 is 'o'

Enter which element of str3 to display (an integer for the subscription): 2
Element #2 of str3 is 'a'

Append str2 to str1:
After appending str1 is:
str1 holds "helloworld" (length = 10)

Comparing str1 and str2...
"helloworld" is less than "world"
Type any non-return key to end the program:
*/