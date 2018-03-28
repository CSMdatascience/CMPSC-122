/*
Author:		Cole Meyers - csm5532
Class:		CMPSC 122
Assignment: 10
File:		C:\Users\Cole Meyers\Documents\School\Penn State\CMPSC 122\projects\assignment10\proj7.cpp
Purpose:	Develop confidence with recursive functions

I certify that this program code is my work. Others may have assisted me with
planning and concepts, but the code was written solely by me.

I understand that submitting code which is totally or partially the product of
other individuals is a violation of the Academic Integrity Policy and accepted
ethical precepts. Falsified execution results are also results of improper
activities. Such violations may results in zero credit for the assignment,
reduced credit for the assignment, or course failure.
*/

#include <iostream>
#include "timer.h"

using namespace std;

//recursive algorithm calculates number of possible northeast paths between two points
int numPaths(int north, int east)
{
	//base case - if either north or east is 0, there is only 1 available path
	if (north == 0 || east == 0)
		return 1;
	/*recursive case - do three things
		1) call numPaths, holding north fixed, and decrementing east by 1 for each call
		2) call numPaths, holding east fixed, and decrementing north by 1 for each call
		3) return the sum of these two values */
	else
		return numPaths(north, east - 1) + numPaths(north - 1, east);
}

int main()
{
	//Timer object will time the numPaths algorithm
	Timer t;

	//north is points north
	//east is points east
	//paths is number of possible paths between start and end points
	int north, east, paths;

	//ans is user's choice to repeat program
	char ans;

	//run program until user decides to quit
	do
	{
		//ask user for points north and east
		cout << "How many points north of A is B?\n";
		cin >> north;
		cout << "How many points east of A is B?\n";
		cin >> east;

		//start timer
		t.start();
		
		//store result of numPaths in paths
		paths = numPaths(north, east);
		
		//stop timer
		t.stop();

		//report paths
		cout << "\nThere are " << paths << " northeast paths between A and B.\n\n";

		//report elapsed time
		t.show();

		//ask user to repeat program
		cout << "\nEnter y or Y to continue next example or any other letter to exit: ";
		cin >> ans;
		
		//convert ans to lower case
		ans = tolower(ans);
		cout << endl;
	} while (ans == 'y');
	return 0;
}

/* Sample Execution:
How many points north of A is B?
2
How many points east of A is B?
3

There are 10 northeast paths between A and B.

Process Timer
-------------------------------
Elapsed Time   : 0.001s

Enter y or Y to continue next example or any other letter to exit: y

How many points north of A is B?
12
How many points east of A is B?
14

There are 9657700 northeast paths between A and B.

Process Timer
-------------------------------
Elapsed Time   : 0.34s

Enter y or Y to continue next example or any other letter to exit: y

How many points north of A is B?
16
How many points east of A is B?
16

There are 601080390 northeast paths between A and B.

Process Timer
-------------------------------
Elapsed Time   : 17.287s

Enter y or Y to continue next example or any other letter to exit: n
*/