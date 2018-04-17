/*
Author:		Cole Meyers - csm5532
Class:		CMPSC 122
Assignment:	13
File:		C:\Users\Cole Meyers\Documents\School\Penn State\CMPSC 122\projects\assignment13\assignment13\proj13.cpp
Purpose:	write and assess the quality of hash functions

I certify that this program code is my work. Others may have assisted me with
planning and concepts, but the code was written solely by me.

I understand that submitting code which is totally or partially the product of
other individuals is a violation of the Academic Integrity Policy and accepted
ethical precepts. Falsified execution results are also results of improper
activities. Such violations may results in zero credit for the assignment,
reduced credit for the assignment, or course failure.
*/

/*PART (a):
Given the C++ function:

unsigned Hash(const string & key, const int h_size)
{
	unsigned int value = 0;
	for (int i = 0; i < key.length(); i++)
		value = (value + key[i]) * 16;
	return value % h_size;
}

The mathematical expression representing Hash() is:
let i		= index, where i = 0 to start
let x[i]	= set of integers with index i
let n		= length of set x, where n >= 1

	Hash == Summation from i to n of [h(x[i]) = x[i] * 16 % 64]
*/


#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

//hash function described in section (b) of assignment sheet
//hash table has a fixed size of 64
unsigned hashB(const string & key)
{
	//define hash table size
	const int h_size = 64;

	//initialize hash value to 0
	unsigned int value = 0;

	//compute hash value
	for (int i = 0; i < key.length(); i++)
		value = (value + key[i]) * 16;

	//apply modulus with respect to table size
	return value % h_size;
}

//hash function described in section (c) of assignment sheet
//hash table has a fixed size of 71
unsigned hashC(const string & key)
{
	//define hash table size
	const int h_size = 71;

	//initialize hash value to 0
	unsigned int value = 0;

	//compute hash value
	for (int i = 0; i < key.length(); i++)
		value = value * 31 + key[i];

	//apply modulus with respect to table size
	return value % h_size;
}

//this function counts the number of collisions 
unsigned collisions(vector<unsigned> val)
{
	//holds number of total collisions
	unsigned numCollisions;

	//first we sort the vector containing hash values, in preparation to apply "unique" iterator
	sort(val.begin(), val.end());

	//numUniques holds number of unique elements in vector
	unsigned numUniques = unique(val.begin(), val.end()) - val.begin();

	//number of collisions = number of keys (i.e. number of hash values) - number of unique hash values
	numCollisions = val.size() - numUniques;

	return numCollisions;
}

int main()
{
	//test set is a file consisting of each letter of the alphabet, all lower case
	ifstream test("don.txt");

	//key is temporary holder of each string in test file
	string key;

	//these vectors will be ordered sets of hash values for each string tested by both hash functions
	vector<unsigned> valB, valC;

	//check for errors opening test file
	if (!test)
	{
		cout << "Error opening test file. Exiting...\n";
		exit(0);
	}
	
	//explanation of test sample
	cout << "The tested input is 'The Temptation of St. Anthony' by Donald Barthelme." << endl << endl <<
		"The story is availble in .txt format at the following Google Drive URL: " << endl << endl <<
		"https://drive.google.com/open?id=1I46B_ZNuBtIYapFa6DkzHTbC277uqNjc" << endl << endl <<
		"The file consists of 2,752 ASCII-encoded English words." << endl << endl;
		
	//read file, compute hash values using both functions, and values in corresponding vectors
	while (test >> key)
	{
		valB.push_back(hashB(key));

		valC.push_back(hashC(key));
	}

	test.close();
	
	int collisionsB, collisionsC;
	
	//calculate number of collisions resulting from each hash function
	collisionsB = collisions(valB);

	collisionsC = collisions(valC);

	//report test results
	cout << "Number of collisions resulting from hash function 'hashB': " << collisionsB << endl
		<< "Number of collisions resulting from hash function 'hashC': " << collisionsC << endl << endl;

	if (collisionsB < collisionsC)
		cout << "Function 'hashB' is the best hash function for the tested input.\n";
	else if (collisionsC < collisionsB)
		cout << "Function 'hashC' is the best hash function for the tested input.\n";
	else
		cout << "Functions 'hashB' and 'hashC' perform equivalently for the tested input.\n";
		
	return 0;
}

/* Sample Execution:
The tested input is 'The Temptation of St. Anthony' by Donald Barthelme.

The story is availble in .txt format at the following Google drive address:

https://drive.google.com/open?id=1I46B_ZNuBtIYapFa6DkzHTbC277uqNjc

The file consists of 2,752 ASCII encoded English words.

Number of collisions resulting from hash function 'hashB': 2748
Number of collisions resulting from hash function 'hashC': 2681

Function 'hashC' is the best hash function for the tested input.
Press any key to continue . . .


***NOTE:
When tested on the lowercase English alphabet, these are the results:

Number of collisions resulting from hash function 'hashB': 22
Number of collisions resulting from hash function 'hashC': 0

Function 'hashC' is the best hash function for the tested input.
Press any key to continue . . .


***CONCLUSION:
hashC is significantly better for single-character keys.

However, with large n, where keys are complete words, the performance of both functions is comparable.
*/