/*
	Alexa Coffin
	Programming Languages
	Project 1
	10/10/2020
*/

#pragma once
#ifndef PARSER_H
#define PARSER_H
#endif // !PARSER_H

#include <iostream>
#include <string>
using namespace std;

class Parser
{
	int current;
	char lookahead;
	string expression;
	string postfix;

	bool inputIsValid(string expression);
	bool isNumber(char c);
	bool isSymbol(char c);
	void expr();
	void rest();
	void term();
	void termRest();
	void factor();
	void digit();
	void match(char terminal);
public:
	string parse(string input);
};

