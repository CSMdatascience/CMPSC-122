/*-------------------------------------------------------------------------*/
/* cmpsc122 Assignment2 test file                                          */
/* File Name: Assign2driver.cpp                                            */
/* cmpsc122                                                                */
/* driver program for assignment 2                                         */
/*-------------------------------------------------------------------------*/

#include "mystring.h"
#include <iostream>
#include <cstring>
using namespace std;

#define MAX_STRING_LENGTH 256

#define ASSURE(b) assure(b, __LINE__)

//Return the length i of string s
int mystrlen(const char *s)
{
	int i = 0;
	while (s[i] != '\0')
		i++;
	return i;
}

/*
Return -1 if s1[0] is less than s2[0]
Return 0 if s1[0] and s2[0] are equal
Return +1 if s1[0] is greater than s2[0]
*/
int mystrcmp(const char *s1, const char *s2)
{
	if (s1[0] < s2[0])
		return -1;
	else if (s1[0] == s2[0])
		return 0;
	else
		return 1;
}

//Copy contents of s2 into s1, return s1
char *mystrcpy(char *s1, const char *s2)
{
	int i = 0;
	for (i; s2[i] != '\0'; i++)
		s1[i] = s2[i];
	s1[i] = '\0';
	return s1;
}

//Concatenate contents of s2 to s1, return s1
char *mystrcat(char *s1, const char *s2)
{
	int i = 0; int j = 0;
	for (i; s1[i] != '\0'; i++);
	for (j; s2[j] != '\0'; j++)
		s1[i + j] = s2[j];
	s1[i + j] = '\0';
	return s1;
}

void assure(bool bSuccessful, int iLineNum)
{
	if (!bSuccessful)
		printf("Test at line %d failed.\n", iLineNum);
}

void testmystrlen(void)
{
	size_t uiResult;

	uiResult = mystrlen("Ruth");
	ASSURE(uiResult == 4);

	uiResult = mystrlen("Gehrig");
	ASSURE(uiResult == 6);

	uiResult = mystrlen("");
	ASSURE(uiResult == 0);
}

void testmystrcmp(void)
{
	int iResult;

	iResult = mystrcmp("Ruth", "Ruth");
	ASSURE(iResult == 0);

	iResult = mystrcmp("Gehrig", "Ruth");
	ASSURE(iResult < 0);

	iResult = mystrcmp("Ruth", "Gehrig");
	ASSURE(iResult > 0);

	iResult = mystrcmp("", "Ruth");
	ASSURE(iResult < 0);

	iResult = mystrcmp("Ruth", "");
	ASSURE(iResult > 0);

	iResult = mystrcmp("", "");
	ASSURE(iResult == 0);
}

void testmystrcpy(void)
{
	char pc[MAX_STRING_LENGTH];
	char *pcResult;

	pcResult = mystrcpy(pc, "Ruth");
	ASSURE(pcResult != NULL);
	ASSURE(pcResult == pc);
	ASSURE((pcResult != NULL) && (strcmp(pc, "Ruth") == 0));

	pcResult = mystrcpy(pc, "");
	ASSURE(pcResult != NULL);
	ASSURE(pcResult == pc);
	ASSURE((pcResult != NULL) && (strcmp(pc, "") == 0));
}


void testmystrcat(void)
{
	char pc[MAX_STRING_LENGTH];
	char *pcResult;

	strcpy(pc, "Ruth");
	pcResult = mystrcat(pc, "Gehrig");
	ASSURE(pcResult != NULL);
	ASSURE(pcResult == pc);
	ASSURE((pcResult != NULL) && (strcmp(pcResult, "RuthGehrig") == 0));

	strcpy(pc, "Ruth");
	pcResult = mystrcat(pc, "");
	ASSURE(pcResult != NULL);
	ASSURE(pcResult == pc);
	ASSURE((pcResult != NULL) && (strcmp(pcResult, "Ruth") == 0));

	strcpy(pc, "");
	pcResult = mystrcat(pc, "Ruth");
	ASSURE(pcResult != NULL);
	ASSURE(pcResult == pc);
	ASSURE((pcResult != NULL) && (strcmp(pcResult, "Ruth") == 0));

	strcpy(pc, "");
	pcResult = mystrcat(pc, "");
	ASSURE(pcResult != NULL);
	ASSURE(pcResult == pc);
	ASSURE((pcResult != NULL) && (strcmp(pcResult, "") == 0));
}

/*
void testmystrstr()
{
char pc[] = "llama";
char pcEmpty[] = "";
char *pcResult;

pcResult = mystrstr(pc, "am");
ASSURE(pcResult == pc + 2);

pcResult = mystrstr(pc, "m");
ASSURE(pcResult == pc + 3);

pcResult = mystrstr(pc, "ll");
ASSURE(pcResult == pc);

pcResult = mystrstr(pc, "l");
ASSURE(pcResult == pc);

pcResult = mystrstr(pc, "llama");
ASSURE(pcResult == pc);

pcResult = mystrstr(pc, "lamal");
ASSURE(pcResult == NULL);

pcResult = mystrstr(pc, "");
ASSURE(pcResult == pc);

pcResult = mystrstr(pcEmpty, "llama");
ASSURE(pcResult == NULL);

pcResult = mystrstr(pcEmpty, "");
ASSURE(pcResult == pcEmpty);
}
*/

int main()
{
	testmystrlen();
	testmystrcmp();
	testmystrcpy();
	testmystrcat();
	//testmystrstr();  

	printf("If no any error outputs, your program passes all the tests. The End.\n");
	return 0;
}

/* Sample execution:
If no any error outputs, your program passes all the tests. The End.
Press any key to continue . . .
*/
