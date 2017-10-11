#include <map>
#include <string>

using namespace std;

// Represents every terminal/non-terminal that could 
// possibly be put onto the stack.
enum StackValues
{
	INTEGER_LITERAL,
	INTEGER_DATA_TYPE,
	BOOLEAN_DATA_TYPE,
	BOOLEAN_LITERAL,
	PLUS_OPERATOR,
	MINUS_OPERATOR,
	DIVIDES_OPERATOR,
	MULTIPLY_OPERATOR,
	FUNCTION,
	LEFT_PAREN,
	RIGHT_PAREN,
	COMMA_LITERAL,
	COLON_LITERAL,
	IDENTIFIER_LITERAL,
	PRINT,
	LESS_THAN_OPERATOR,
	EQUAL_SIGN,
	AND,
	OR,
	NOT,
	IF,
	THEN,
	ELSE,
	END_OF_STREAM,
	PROGRAM,
	DEFINITIONS,
	DEF,
	FORMALS,
	NON_EMPTY_FORMALS,
	NON_EMPTY_FORMALS_TAIL,
	FORMAL,
	BODY,
	TYPE,
	EXPR,
	EXPR_TAIL,
	SIMPLE_EXPR,
	SIMPLE_EXPR_TAIL,
	TERM,
	TERM_TAIL,
	FACTOR,
	FACTOR_ID_TAIL,
	ACTUALS,
	NON_EMPTY_ACTUALS,
	NON_EMPTY_ACTUALS_TAIL,
	LITERAL,
	PRINT_STATEMENT,
	BUILD_PROGRAM_NODE,
	BUILD_DEFINITIONS_NODE,
	BUILD_IDENTIFIER_NODE,
	BUILD_DEF_NODE,
	BUILD_FORMALS_NODE,
	BUILD_NONEMPTYFORMALS_NODE,
	BUILD_FORMAL_NODE,
	BUILD_BODY_NODE,
	BUILD_TYPE_NODE,
	BUILD_LESSTHAN_NODE,
	BUILD_EQUAL_NODE,
	BUILD_BASEEXPR_NODE,
	BUILD_OR_NODE,
	BUILD_ADDITION_NODE,
	BUILD_SUBTRACTION_NODE,
	BUILD_BASESIMPLEEXPR_NODE,
	BUILD_AND_NODE,
	BUILD_MULTIPLICATOR_NODE,
	BUILD_DIVIDER_NODE,
	BUILD_BASETERM_NODE,
	BUILD_IFFACTOR_NODE,
	BUILD_NOTFACTOR_NODE,
	BUILD_LITERALFACTOR_NODE,
	BUILD_SUBTRACTIONFACTOR_NODE,
	BUILD_PARENEXPR_NODE,
	BUILD_IDENTIFIERACTUALS_NODE,
	BUILD_SINGLETONIDENTIFIERFACTOR_NODE,
	BUILD_BASEACTUALS_NODE,
	BUILD_NONBASEACTUALS_NODE,
	BUILD_NONEMPTYACTUALS_NODE,
	BUILD_INTEGERLITERAL_NODE,
	BUILD_BOOLEANLITERAL_NODE,
	BUILD_PRINTSTATEMENT_NODE
};

//TODO: Probably need to put semantic actions in here for future error messages
const map<StackValues, string> StackValuesPrintMap {
	{ INTEGER_LITERAL, "INTEGER_LITERAL" },
	{ INTEGER_DATA_TYPE, "INTEGER_DATA_TYPE" },
	{ BOOLEAN_DATA_TYPE, "BOOLEAN_DATA_TYPE" },
	{ BOOLEAN_LITERAL, "BOOLEAN_LITERAL" },
	{ PLUS_OPERATOR, "PLUS_OPERATOR { + }" },
	{ MINUS_OPERATOR, "MINUS_OPERATOR { - }" },
	{ DIVIDES_OPERATOR, "DIVIDES_OPERATOR { / } " },
	{ MULTIPLY_OPERATOR, "MULTIPLY_OPERATOR { * }" },
	{ FUNCTION, "FUNCTION" },
	{ LEFT_PAREN, "LEFT_PAREN  { ( }" },
	{ RIGHT_PAREN, "RIGHT_PAREN { ) }" },
	{ COMMA_LITERAL, "COMMA_LITERAL { , }" },
	{ COLON_LITERAL, "COLON_LITERAL { : }" },
	{ IDENTIFIER_LITERAL, "IDENTIFIER_LITERAL" },
	{ PRINT, "PRINT" },
	{ LESS_THAN_OPERATOR, "LESS_THAN_OPERATOR { < }" },
	{ EQUAL_SIGN, "EQUAL_SIGN { = }" },
	{ AND, "AND" },
	{ OR, "OR" },
	{ NOT, "NOT" },
	{ IF, "IF" },
	{ THEN, "THEN" },
	{ ELSE, "ELSE" },
	{ END_OF_STREAM, "END_OF_STREAM" },
	{ PROGRAM, "PROGRAM" },
	{ DEFINITIONS, "DEFINITIONS" },
	{ DEF, "DEF" },
	{ FORMALS, "FORMALS" },
	{ NON_EMPTY_FORMALS, "NON_EMPTY_FORMALS" },
	{ NON_EMPTY_FORMALS_TAIL, "NON_EMPTY_FORMALS_TAIL" },
	{ FORMAL, "FORMAL" },
	{ BODY, "BODY" },
	{ TYPE, "TYPE" },
	{ EXPR, "EXPR" },
	{ EXPR_TAIL, "EXPR_TAIL" },
	{ SIMPLE_EXPR, "SIMPLE_EXPR" },
	{ SIMPLE_EXPR_TAIL, "SIMPLE_EXPR_TAIL" },
	{ TERM, "TERM" },
	{ TERM_TAIL, "TERM_TAIL" },
	{ FACTOR, "FACTOR" },
	{ FACTOR_ID_TAIL, "FACTOR_ID_TAIL" },
	{ ACTUALS, "ACTUALS" },
	{ NON_EMPTY_ACTUALS, "NON_EMPTY_ACTUALS" },
	{ NON_EMPTY_ACTUALS_TAIL, "NON_EMPTY_ACTUALS_TAIL" },
	{ LITERAL, "LITERAL" },
	{ PRINT_STATEMENT, "PRINT_STATEMENT" }
};