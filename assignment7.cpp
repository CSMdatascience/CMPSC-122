/*
Author:		Cole Meyers - csm5532
Class:		CMPSC 122
Assignment: 7
File:		C:\Users\Cole Meyers\Documents\School\Penn State\CMPSC 122\projects\proj7\proj7\proj5-grademe.cpp
Purpose:	practice using stacks; evaluate RPN expressions

I certify that this program code is my work. Others may have assisted me with
planning and concepts, but the code was written solely by me.

I understand that submitting code which is totally or partially the product of
other individuals is a violation of the Academic Integrity Policy and accepted
ethical precepts. Falsified execution results are also results of improper
activities. Such violations may results in zero credit for the assignment,
reduced credit for the assignment, or course failure.
*/

#include <iostream>
#include <stack>
#include <string>

using namespace std;

//Check for syntax errors in a token
bool tokenError(char token[], stack<double> S);

//Convert numeric token to double; push onto stack
void tokenNum(char token[], stack<double> & S);

//Sum of two tokens (top two on stack)
void tokenPlus(char token[], stack<double> & S);

//Difference of two tokens
void tokenMinus(char token[], stack<double> & S);

//Product of two tokens
void tokenMult(char token[], stack<double> & S);

//Quotient of two tokens
void tokenDiv(char token[], stack<double> & S);

//Reports number on top of stack (result of expression)
void tokenDelimit(char token[], stack<double> & S);

int main()
{
	stack<double> S;			//hold each number in the expression
	char token[256];			//hold each successive element in the expression
	char ans;					//user's choice to repeat program
	bool errorState = false;	//flag is set true if syntax error in expression

	cout << "(Note: Each digit or operator should be separated by a space, and end with :)\n"
		<< "Please enter the RPN expression to be evaluated.\n";

	do {
		//First check to make sure stack starts empty
		while (!S.empty())
			S.pop();

		//Ask user for expression, BUT ONLY TAKES FIRST TOKEN
		cin >> token;

		//Handle all tokens that do not begin with the delimiter
		while (token[0] != ':')
		{
			//Print token currently being handled
			cout << "Token = " << token << " ";

			//Check for errors in syntax
			if (tokenError(token, S))
			{
				//Set error flag so that tokenDelimit does not execute
				errorState = true;

				//Read any remaining user input after the error
				cin.getline(token, std::numeric_limits<std::streamsize>::max());

				//Clear the input stream for next iteration
				cin.clear();
				cout << "\nPlease enter a new expression.\n";

				//Exit while loop (move on to next iteration)
				break;
			}
			else if (isdigit(token[0]))
			{
				tokenNum(token, S);
				cin >> token;
			}
			else if (token[0] == '+')
			{
				tokenPlus(token, S);
				cin >> token;
			}
			else if (token[0] == '-')
			{
				tokenMinus(token, S);
				cin >> token;
			}
			else if (token[0] == '*')
			{
				tokenMult(token, S);
				cin >> token;
			}
			else if (token[0] == '/')
			{
				tokenDiv(token, S);
				cin >> token;
			}
		}

		if (errorState == false)
		{
			//Report result of expression
			tokenDelimit(token, S);

			//Ask user to repeat or quit
			cout << "Type 'Y' or 'y' to continue or type any other letter to quit: ";
			cin >> ans;
			cout << endl;

			//Convert choice to lower case
			ans = tolower(ans);

			if (ans == 'y')
				cout << "Please enter the RPN expression to be evaluated.\n";
		}
		else
		{
			ans = 'y';

			//Reset error flag for next iteration
			errorState = false;
		}
	} while (ans == 'y');

	return 0;
}

bool tokenError(char token[], stack<double> S)
{
	//Most basic obvious error case - token[0] does not match any acceptable input
	if ((!isdigit(token[0])) && (token[0] != '+') && (token[0] != '-') && (token[0] != '*') && (token[0] != '/') && (token[0] != ':'))
	{
		cout << "\nERROR: please enter only numbers and the operators +, -, *, /, :.\n";
		return true;
	}
	//If token[0] is numeric, inspect rest of token for validity
	else if (isdigit(token[0]))
	{
		//Flag is not necessary (everything could have gone inside the for loop)
		bool flag = false;

		//if any characters after token[0] are not numeric, token is invalid
		for (int i = 0; i < strlen(token); i++)
			if (!isdigit(token[i]) && (token[i] != '.'))
				flag = true;
		if (flag == true)
		{
			cout << "\nERROR: numeric elements may only contain numbers and a decimal point.\n";
			return true;
		}
			
		else
			return false;
	}
	//If token[0] is an accepted operator, inspect rest of token for validity
	else if ((token[0] == '+') || (token[0] == '-') || (token[0] == '*') || (token[0] == '/') || (token[0] == ':'))
	{
		//If length of token is anything but 1, token is invalid
		if (strlen(token) != 1)
		{
			cout << "\nERROR: separate each element in the expression by a space (' ').\n";
			return true;
		}
		//If there are less than 2 numbers in the stack, something is also wrong
		else if (S.size() < 2)
		{
			cout << "\nERROR: less than two digits entered prior to operator.\n";
			return true;
			
		}
		//Check for divide by zero case
		else if ((token[0] == '/') && (S.top() == 0))
		{
			cout << "\nERROR: cannot divide by zero.\n";
			return true;
		}
		else
			return false;
	}
	//Catch-all case: Since all error-free cases are managed in previous statements, anything else will throw an error
	else
	{
		cout << "\nERROR: unclassified.\n";
		return true;
	}
		
}

void tokenNum(char token[], stack<double> & S)
{

	double num;

	//convert char[] to double
	num = strtod(token, NULL);

	//Push num onto stack and report operation to user
	S.push(num);
	cout << "Push " << S.top() << endl;
}

void tokenPlus(char token[], stack<double> & S)
{
	double left, right, sum;

	//num at top of stack becomes "right-hand" operand; remove from stack
	right = S.top();
	S.pop();
	cout << "Pop " << right;

	//num on new top of stack becomes "left-hand" operand; remove from stack
	left = S.top();
	S.pop();
	cout << " Pop " << left;

	//compute sum; push onto stack
	sum = left + right;
	S.push(sum);
	cout << " Push " << sum << endl;
}

void tokenMinus(char token[], stack<double> & S)
{
	double left, right, diff;

	right = S.top();
	S.pop();
	cout << "Pop " << right;

	left = S.top();
	S.pop();
	cout << " Pop " << left;

	diff = left - right;
	S.push(diff);
	cout << " Push " << diff << endl;
}

void tokenMult(char token[], stack<double> & S)
{
	double left, right, prod;

	right = S.top();
	S.pop();
	cout << "Pop " << right;

	left = S.top();
	S.pop();
	cout << " Pop " << left;

	prod = left * right;
	S.push(prod);
	cout << " Push " << prod << endl;
}

void tokenDiv(char token[], stack<double> & S)
{
	double left, right, quo;

	
	right = S.top();
	S.pop();
	cout << "Pop " << right;

	left = S.top();
	S.pop();
	cout << " Pop " << left;

	quo = left / right;
	S.push(quo);
	cout << " Push " << quo << endl;
}

void tokenDelimit(char token[], stack<double> & S)
{
	cout << "Token = Pop " << S.top() << endl;

	S.pop();
}

/* Sample Execution:
(Note: Each digit or operator should be separated by a space, and end with :)
Please enter the RPN expression to be evaluated.
a 1 + :
Token = a
ERROR: please enter only numbers and the operators +, -, *, /, :.

Please enter a new expression.
1a 1 + :
Token = 1a
ERROR: numeric elements may only contain numbers and a decimal point.

Please enter a new expression.
1 1 1 +- :
Token = 1 Push 1
Token = 1 Push 1
Token = 1 Push 1
Token = +-
ERROR: separate each element in the expression by a space (' ').

Please enter a new expression.
1 + :
Token = 1 Push 1
Token = +
ERROR: less than two digits entered prior to operator.

Please enter a new expression.
1 0 / :
Token = 1 Push 1
Token = 0 Push 0
Token = /
ERROR: cannot divide by zero.

Please enter a new expression.
9 2 1 + / 4 * :
Token = 9 Push 9
Token = 2 Push 2
Token = 1 Push 1
Token = + Pop 1 Pop 2 Push 3
Token = / Pop 3 Pop 9 Push 3
Token = 4 Push 4
Token = * Pop 4 Pop 3 Push 12
Token = Pop 12
Type 'Y' or 'y' to continue or type any other letter to quit: y

Please enter the RPN expression to be evaluated.
99 22 11 + / 44 * :
Token = 99 Push 99
Token = 22 Push 22
Token = 11 Push 11
Token = + Pop 11 Pop 22 Push 33
Token = / Pop 33 Pop 99 Push 3
Token = 44 Push 44
Token = * Pop 44 Pop 3 Push 132
Token = Pop 132
Type 'Y' or 'y' to continue or type any other letter to quit: y

Please enter the RPN expression to be evaluated.
1.5 10 * 3 / 5 + 3.5 - :
Token = 1.5 Push 1.5
Token = 10 Push 10
Token = * Pop 10 Pop 1.5 Push 15
Token = 3 Push 3
Token = / Pop 3 Pop 15 Push 5
Token = 5 Push 5
Token = + Pop 5 Pop 5 Push 10
Token = 3.5 Push 3.5
Token = - Pop 3.5 Pop 10 Push 6.5
Token = Pop 6.5
Type 'Y' or 'y' to continue or type any other letter to quit: y
*/