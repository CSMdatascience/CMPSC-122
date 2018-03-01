using namespace std;

class String {
	char str[256];
	int len;

public:

	// A default constructor that sets up the String to be an empty string.
	String();


	// A method that copies the contents of the passed string into the String.
	void assign(const char s[]);


	//A method that appends the contents of the passed String onto the end of the String the method is called on.
	void append(const String &s);


	/*A method that compares the String this method is called on with the String passed to the method.
	If the string is greater than the string passed, it should return a positive value;
	if less than, a negative value, and if equal, the value zero.*/
	int compare_to(const String &str) const;


	//A method that prints the value of the String it is called on to cout.
	void print() const;


	//A method that returns the length of the String that it is called on.
	int length() const;


	/*A method that returns the i - th element(zero - based, just like arrays) of the String it is called on.
	This method should print out an error message and return the null character(\0)
	if the location asked for is out - of - range for the string.*/
	char element(int i) const;


};

