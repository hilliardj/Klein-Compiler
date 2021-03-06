#include <iostream>
#include "header/Parser.h"
#include "header/Scanner.h"
#include "header/SemanticChecker.h"

void printSymbolTable(SemanticChecker SemanticChecker);

const map<ReturnTypes, string> ReturnTypePrintMap{
	{ INTEGER_TYPE, "Integer" },
	{ BOOLEAN_TYPE, "Boolean" },
	{ OR_TYPE, "Or Type (boolean or integer)" },
	{ NO_RETURN_TYPE, "None" }
};

int main(int argv, char* argc[])
{
	if (argv == 1) {
		cout << "Please insert a KLEIN file to semantically validate." << endl;
		return 1;
	}

	try
	{
		Scanner Scanner(argc[1], 1);
		Parser Parser(Scanner);
		Parser.parseProgram();

		ASTNode AST = Parser.getFinalASTNode();
		SemanticChecker SemanticCheckerVar = SemanticChecker(AST);

		// print warnings
		for (int i = 0; i < SemanticCheckerVar.getWarnings().size(); i++)
		{
			cout << SemanticCheckerVar.getWarnings().at(i) << endl;
		}

		// print Errors, and if there are none, then print the symbol table
		if (SemanticCheckerVar.getErrors().empty())
		{
			printSymbolTable(SemanticCheckerVar);
		}
		else {
			for (int i = SemanticCheckerVar.getErrors().size() - 1; i  >= 0; i--)
			{
				cout << SemanticCheckerVar.getErrors().at(i) << endl;
			}
		}
	}
	catch (const std::exception& e)
	{
		//Print Error Message (that isn't a semantic error)
		cout << endl << e.what() << endl;
		return 1;
	}
	return 0;
}

void printSymbolTable(SemanticChecker SemanticChecker) {
	map<string, Function>::iterator Iterator;
	map<string, Function> SymbolTable = SemanticChecker.getSymbolTable();

	// Loop through every function in the symbol table
	for (Iterator = SymbolTable.begin(); Iterator != SymbolTable.end(); Iterator++) {
		cout << "FUNCTION NAME: " << Iterator->first << endl;

		// Print return type
		cout << "   RETURN TYPE: " << endl;
		cout << "       " << ReturnTypePrintMap.find(Iterator->second.getReturnType())->second << endl;

		// Print varaibles
		cout << "   VARIABLES: ";
		if (Iterator->second.getParameters().empty()) {
			cout << "no variables..." << endl;
		}
		else {
			cout << endl;
		}

		for (int i = 0; i < Iterator->second.getParameters().size(); i++)
		{
			cout << "       name: " 
				<< get<0>(Iterator->second.getParameters().at(i)) 
				<< ", type: " 
				<< ReturnTypePrintMap.find(get<1>(Iterator->second.getParameters().at(i)))->second << endl;
		}

		// Print every function that calls this function
		cout << "   FUNCTION CALLERS: ";
		if (Iterator->second.getFunctionCallers().empty()) {
			cout << "no function callers..." << endl;
		}
		else {
			cout << endl;
		}

		for (int i = 0; i < Iterator->second.getFunctionCallers().size(); i++)
		{
			cout << "      function name: " << Iterator->second.getFunctionCallers().at(i) << endl;
		}

		cout << endl;
	}
}