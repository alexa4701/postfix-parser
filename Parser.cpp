/*
	Alexa Coffin
	Programming Languages
	Project 1
	10/10/2020
*/

#include "Parser.h"

string Parser::parse(string input)
{
	current = 0;
	lookahead = '!';
	postfix = "";
	expression = input;

	if (inputIsValid(expression))
	{
		lookahead = expression[current];
		expr();
		if (inputIsValid(postfix))
		{
			return postfix;
		}
		else
		{
			return "Syntax error\n";
		}
	}

	return "Syntax error, string contains invalid characters.";
}

bool Parser::inputIsValid(string expression)
{

	for (int i = 0; i < expression.length(); i++)
	{
		if (isSymbol(expression[i]) || isNumber(expression[i]))
		{
			continue;
		}
		cout << "Invalid character" << endl;
		return false;
	}

	return true;
}

bool Parser::isNumber(char c)
{
	string numbers = "0123456789";

	return !(numbers.find(c) == -1);
}

bool Parser::isSymbol(char c)
{
	string symbols = "+-*/()";

	return !(symbols.find(c) == -1);
}

void Parser::expr() 
{
	if (isNumber(lookahead) || lookahead == '(')
	{
		term();
		rest();
	}
	else
	{
		cout << "Syntax error, invalid first symbol for expr." << endl;
		postfix.push_back('!');
	}
}

void Parser::rest() 
{
	if (lookahead == '+')
	{
		match('+');
		term();
		postfix.push_back('+');
		rest();
	}
	else if (lookahead == '-')
	{
		match('-');
		term();
		postfix.push_back('-');
		rest();
	}
	else if (isNumber(lookahead))
	{
		cout << "Syntax error." << endl;
		postfix.push_back('!');
	}
	else ; // Empty case, do nothing with input.
}

void Parser::term() 
{
	if (isNumber(lookahead) || lookahead == '(')
	{
		factor();
		termRest();
	}
}

void Parser::termRest()
{
	if (lookahead == '*')
	{
		match('*');
		factor();
		postfix.push_back('*');
		termRest();
	}
	else if (lookahead == '/')
	{
		match('/');
		if (lookahead == '0')
		{
			cout << "Syntax error, divide by zero." << endl;
			postfix.push_back('!');
		}
		else
		{
			factor();
			postfix.push_back('/');
			termRest();
		}
	}
	else ; // Empty case, do nothing with input.
}

void Parser::factor() 
{
	if (isNumber(lookahead))
	{
		digit();
	}
	else if (lookahead == '(')
	{
		match('(');
		expr();
		match(')');
	}
}

void Parser::digit() 
{
	switch (lookahead)
	{
		case '0':
			match('0');
			postfix.push_back('0');
			break;
		case '1':
			match('1');
			postfix.push_back('1');
			break;
		case '2':
			match('2');
			postfix.push_back('2');
			break;
		case '3':
			match('3');
			postfix.push_back('3');
			break;
		case '4':
			match('4');
			postfix.push_back('4');
			break;
		case '5':
			match('5');
			postfix.push_back('5');
			break;
		case '6':
			match('6');
			postfix.push_back('6');
			break;
		case '7':
			match('7');
			postfix.push_back('7');
			break;
		case '8':
			match('8');
			postfix.push_back('8');
			break;
		case '9':
			match('9');
			postfix.push_back('9');
			break;
		default:
			cout << "Syntax error, invalid digit" << endl;
			postfix.push_back('!');
	}
}

void Parser::match(char terminal) 
{
	if (lookahead == terminal)
	{
		current++;
		lookahead = expression[current];
	}
	else
	{
		cout << "Syntax error, terminal does not match lookahead." << endl;
		postfix.push_back('!');
	}
}