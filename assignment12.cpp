/*
Author:		Cole Meyers - csm5532
Class:		CMPSC 122
Assignment:	12 - Binary Search Trees
File:		C:\Users\Cole Meyers\Documents\School\Penn State\CMPSC 122\projects\assignment12\assignment12\proj12.cpp
Purpose:	gain experience with operations involving binary search trees

I certify that this program code is my work. Others may have assisted me with
planning and concepts, but the code was written solely by me.

I understand that submitting code which is totally or partially the product of
other individuals is a violation of the Academic Integrity Policy and accepted
ethical precepts. Falsified execution results are also results of improper
activities. Such violations may results in zero credit for the assignment,
reduced credit for the assignment, or course failure.
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//Data stored in the node type
struct WordCount
{
	string word;

	int count;
};

//Node type: 
struct TreeNode
{
	WordCount info;

	TreeNode * left;

	TreeNode * right;
};

//Increments the frequency count if the string is in the tree or inserts the string if it is not there.
void Insert(TreeNode * & node, string word)
{
	//if no root node exists, create one
	if (node == NULL)
	{
		node = new TreeNode;
		node->info.word = word;
		node->info.count = 1;
		node->left = node->right = NULL;
	}
	//if word is lexicographically less than root, add to left side of BST
	else if (word < node->info.word)
		Insert(node->left, word);
	//if word is lexicographically greater than root, add to right side of BST
	else if (word > node->info.word)
		Insert(node->right, word);
	//if word has already appeared in file, increment this word's count
	else
		node->info.count++;
}


//Prints the words in the tree and their frequency counts.
void PrintTree(TreeNode * tree, ofstream & outFile)
{
	//if tree is empty, do nothing
	if (tree == NULL)
		return;
	
	//begin in-order traversal
	
	//print left side of BST
	PrintTree(tree->left, outFile);

	//print root node
	outFile << tree->info.word << " " << tree->info.count << endl;

	//print right side of BST
	PrintTree(tree->right, outFile);
}

int main()
{
	//initialize root node as NULL (neglecting to do so results in VS error C4730 - potentially uninitialized pointer...)
	TreeNode * root(NULL);

	//user-specified input file path; output file will be saved in same directory
	string inFileName;

	//user-specified output file name
	string outFileName;

	//ask user for input path
	cout << "Please enter the input text file name: ";
	cin >> inFileName;

	//ask user for output name
	cout << "Please enter the output text file name: ";
	cin >> outFileName;

	//input file stream
	ifstream inFile(inFileName);

	//if file is inaccessible at specified path, throw error and exit
	if (!inFile)
	{
		cerr << "Error: Failed to open input file. Exiting...\n";
		exit(0);
	}
	//add each word in inFile to BST
	else
	{
		string word;
		//build BST
		while (inFile >> word)
		{
			//remove any non-alphanumeric characters from each word (punctuation)
			if (!isalnum(word[word.length() - 1]))
				word.erase(word.length() - 1);

			//if word is still longer than 2 characters after removing punctuation, insert into BST
			if (word.length() > 2)
				Insert(root, word);
		}
	}

	//close inFile
	inFile.close();

	//output file stream
	ofstream outFile(outFileName);

	//error case where outFile does not open
	if (!outFile)
	{
		cerr << "Error: Failed to open output file. Exiting...\n";
		exit(0);
	}
	//print entire BST IN-ORDER to output file
	else
		PrintTree(root, outFile);

	outFile.close();

	cout << "Output file is now available in the same directory as the input file.\n\n";

	return 0;
}

/*Sample execution:
Please enter the input text file name: lincoln.txt
Please enter the output text file name: csm5532.txt
Output file is now available in the same directory as the input file.
*/