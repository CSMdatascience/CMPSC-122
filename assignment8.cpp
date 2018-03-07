/*
Author:		Cole Meyers - csm5532
Class:		CMPSC 122
Assignment:	8
File:		C:\Users\Cole Meyers\Documents\School\Penn State\CMPSC 122\projects\assignment8\assignment8\assignment8.cpp
Purpose:	practice using STL containers and algorithms

I certify that this program code is my work. Others may have assisted me with
planning and concepts, but the code was written solely by me.

I understand that submitting code which is totally or partially the product of
other individuals is a violation of the Academic Integrity Policy and accepted
ethical precepts. Falsified execution results are also results of improper
activities. Such violations may results in zero credit for the assignment,
reduced credit for the assignment, or course failure.
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() 
{
	//holds number of test cases to be examined
	int cases;	

	//ask user for input
	cout << "Input:\n";	

	//user enters number of test cases
	cin >> cases;			

	//find minimum sum of distances (median)
	while (cases--)
	{
		//holds number of relatives in current case
		int size;	

		//user enters number of relatives
		cin >> size;	

		//holds distances 
		vector<int> distances(size);	

		//holds street number of each relative
		vector<int> streets(size);	

		//user enters street number of each family member
		for (int i = 0; i < size; i++)
			cin >> streets.at(i);
		
		for (int i = 0; i < size; i++)
		{
			//holds sum of absolute value of distance between pairs of street numbers
			int sum = 0;

			//find absolute value of distance between each pair of streets
				//add result to sum
			for (int j = 0; j < size; j++)
				if (j != i)
					sum += abs(streets.at(i) - streets.at(j));

			//add sum of first set to distances vector
			distances.at(i) = sum;

			//resets sum counter to zero
			sum = 0;
		}

		cout << "Output:\n" << *min_element(distances.begin(), distances.end()) << endl;
		//report minimum element in distances vector for current test case
		//cout << "Output:\n" <<  << endl;
	}
	return 0;
}

/* Sample Execution:
Input:
2
2 2 4
Output:
2
3 2 4 6
Output:
4
Press any key to continue . . .

Input:
1
10 2 12 23 10 3 40 20 19 4 10
Output:
85
Press any key to continue . . .

Input:
1
2 30000 1
Output:
29999
Press any key to continue . . .
*/