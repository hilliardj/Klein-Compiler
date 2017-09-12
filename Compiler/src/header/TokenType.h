#pragma once
#include <map>
#include <string>

using namespace std;

enum TokenType
{
	INTEGER,
	BOOLEAN,
	DATA_TYPE,
	ARITHMETIC_OPERATOR,
	PRIMITIVE_KEYWORD,
	PARENTHESIS,
	COMMA,
	COLON,
	IDENTIFIER,
	COMPARATOR,
	LOGICIAL_OPERATOR,
	CONDITIONAL,
	END_OF_FILE
};

const map<TokenType, string> TokenTypePrintMap {
	{ INTEGER, "INTEGER" },
	{ BOOLEAN, "BOOLEAN" },
	{ ARITHMETIC_OPERATOR, "ARITHMETIC_OPERATOR" },
	{ PRIMITIVE_KEYWORD, "PRIMITIVE_KEYWORD" },
	{ PARENTHESIS, "PARENTHESIS" },
	{ COMMA, "COMMA" },
	{ COLON, "COLON" },
	{ IDENTIFIER, "IDENTIFIER" },
	{ COMPARATOR, "COMPARATOR" },
	{ LOGICIAL_OPERATOR, "LOGICIAL_OPERATOR" },
	{ CONDITIONAL, "CONDITIONAL" },
	{ END_OF_FILE, "END_OF_FILE" }
};
