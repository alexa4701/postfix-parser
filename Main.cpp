/*
	Alexa Coffin
	Programming Languages
	Project 1
	10/10/2020
*/

#include "Parser.h"

void program()
{
	string input = "";
	Parser p;

	cout << "Welcome!" << endl;
	cout << "This program converts infix expressions to postfix notation." << endl;
	while (input.compare("exit") != 0)
	{
		cout << endl << "Enter an expression (only 0-9, +, -, /, *, (, and ) are allowed): " << endl;
		cin >> input;
		if (input.compare("exit") != 0)
		{
			cout << endl << "Result: " << p.parse(input) << endl;
		}
	}
}

int main()
{
	program();
}