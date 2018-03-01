/*
Author:		Cole Meyers - csm5532
Class:		CMPSC 122
Assignment: 6
File:		C:\Users\Cole Meyers\Documents\School\Penn State\CMPSC 122\projects\proj6\proj6\mystring.h
Purpose:	class object - overloading operators, internal and external

I certify that this program code is my work. Others may have assisted me with
planning and concepts, but the code was written solely by me.

I understand that submitting code which is totally or partially the product of
other individuals is a violation of the Academic Integrity Policy and accepted
ethical precepts. Falsified execution results are also results of improper
activities. Such violations may results in zero credit for the assignment,
reduced credit for the assignment, or course failure.
*/
#ifndef _MYSTRING_H
#define _MYSTRING_H
class String {
	char * str;
	int len;

	friend std::ostream & operator << (std::ostream & out, const String & s);

public:

	//Destructor
	~String();

	// A default constructor that sets up the String to be an empty string.
	String();

	//Copy constructor
	String(const String & original);

	//Assignment overloading
	String & operator = (const String & original);

	//Constructor that initializes String object to string s - functionally same as void assign
	String(const char s[]);

	//Concatenation function - functionally same as void append
	String operator+=(const String & original);

	//Gets the ith element in a string - functionally same as char element
	char operator [](int i) const;

	//Checks for equality - same as compare_to's "0" condition
	bool operator ==(const String &str) const;

	//Checks for inequality
	bool operator !=(const String &str) const;

	//Checks for greater-than condition
	bool operator > (const String &str) const;

	//Checks for less-than condition
	bool operator < (const String &str) const;

	//A method that prints the value of the String it is called on to cout.
	void print() const;

	//Prints string to an ostream object - functionally same as void print
	void print(std::ostream & out) const;

	// A method that copies the contents of the passed string into the String.
	void assign(const char s[]);

	//A method that appends the contents of the passed String onto the end of the String the method is called on.
	void append(const String &s);

	/*A method that compares the String this method is called on with the String passed to the method.
	If the string is greater than the string passed, it should return a positive value;
	if less than, a negative value, and if equal, the value zero.*/
	int compare_to(const String &str) const;

	//A method that returns the length of the String that it is called on.
	int length() const;


	/*A method that returns the i - th element(zero - based, just like arrays) of the String it is called on.
	This method should print out an error message and return the null character(\0)
	if the location asked for is out - of - range for the string.*/
	char element(int i) const;


};

#endif