#pragma once
//Return the length i of string s
int mystrlen(const char *s);

/*
Return -1 if s1[0] is less than s2[0]
Return 0 if s1[0] and s2[0] are equal
Return +1 if s1[0] is greater than s2[0]
*/
int mystrcmp(const char *s1, const char *s2);


//Copy contents of s2 into s1, return s1
char *mystrcpy(char *s1, const char *s2);


//Concatenate contents of s2 to s1, return s1
char *mystrcat(char *s1, const char *s2);
