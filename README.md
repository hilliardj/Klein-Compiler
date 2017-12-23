     $$$$$$\   $$$$$$\  $$\      $$\ $$$$$$$\ $$$$$$\ $$\       $$$$$$$$\ $$$$$$$\  
     $$  __$$\ $$  __$$\ $$$\    $$$ |$$  __$$\\_$$  _|$$ |      $$  _____|$$  __$$\ 
     $$ /  \__|$$ /  $$ |$$$$\  $$$$ |$$ |  $$ | $$ |  $$ |      $$ |      $$ |  $$ |
     $$ |      $$ |  $$ |$$\$$\$$ $$ |$$$$$$$  | $$ |  $$ |      $$$$$\    $$$$$$$  |
     $$ |      $$ |  $$ |$$ \$$$  $$ |$$  ____/  $$ |  $$ |      $$  __|   $$  __$$< 
     $$ |  $$\ $$ |  $$ |$$ |\$  /$$ |$$ |       $$ |  $$ |      $$ |      $$ |  $$ |
     \$$$$$$  | $$$$$$  |$$ | \_/ $$ |$$ |     $$$$$$\ $$$$$$$$\ $$$$$$$$\ $$ |  $$ |
      \______/  \______/ \__|     \__|\__|     \______|\________|\________|\__|  \__|
                                                                                
                                                                                
                                                                                
     $$$$$$$\  $$$$$$$$\ $$$$$$$$\ $$$$$$\ $$\       $$$$$$$$\ $$$$$$$\   $$$$$$\    
     $$  __$$\ $$  _____|$$  _____|\_$$  _|$$ |      $$  _____|$$  __$$\ $$  __$$\   
     $$ |  $$ |$$ |      $$ |        $$ |  $$ |      $$ |      $$ |  $$ |$$ /  \__|  
     $$ |  $$ |$$$$$\    $$$$$\      $$ |  $$ |      $$$$$\    $$$$$$$  |\$$$$$$\    
     $$ |  $$ |$$  __|   $$  __|     $$ |  $$ |      $$  __|   $$  __$$<  \____$$\   
     $$ |  $$ |$$ |      $$ |        $$ |  $$ |      $$ |      $$ |  $$ |$$\   $$ |  
     $$$$$$$  |$$$$$$$$\ $$ |      $$$$$$\ $$$$$$$$\ $$$$$$$$\ $$ |  $$ |\$$$$$$  |  
     \_______/ \________|\__|      \______|\________|\________|\__|  \__| \______/ 
-----------------------------------------------------------------------------------------

## BEFORE WE GET STARTED
I was the team lead for this compiler project which took the entire Fall semester. 
It was an amazing learning experience and it fundamentally changed the way I think
about computer science/programming. If you want to understand the nature of this
project fully, keep on reading. If you just want to see the final product/how to 
run it, then I encourage you to check out the [Demo folder](/Demo) which contains
gifs of the final product and some information regaurding the development process.


Hello, we are the compiler defilers. Our Group Consists of:
* [Justice Adams (adamsjal@uni.edu)](https://github.com/justiceadamsUNI)
* [Harsha Varma (varmak@uni.edu)](https://github.com/harshavarmak)
* [Joshua Hilliard (hilliarj@uni.edu)](https://github.com/hilliardj)

This is the code repository for the Klein Compiler we are writing. We are 
implementing a Klein compiler that will translate .kln files into machine 
language. This compiler implementation is written in C++. Currently, we have a
working Scanner which converts characters in a .kln file into tokens, a 
parser that validates Klein programs and produces an AST tree, a Semantic 
analyzer for static code analysis on a given AST tree, and a full code
generator that outputs a .tm file. We developed this using a feature-branch 
workflow utilizing  Github.  You'll notice the repo has an extra outer directory
for various reasons including continuous integration purposes.


**A quick note about Visual Studio.** If you don't intend to edit this using 
visual studio, ignore the Compiler.sln, Compiler.vcxproj, 
Compiler.vcxproj.filters files that are in the /misc folder. If you are a VS 
user, they will make your life easier if you move them out to the root 
directory and open the solution!



## PROJECT STRUCTURE:
-----------------------------------------------------------------------------------------
![Project Structure](https://i.imgur.com/gBPuSSq.png)
	
**SRC:** A directory containing all code for the project. Header files can be 
	found in /header and implementation files of those headers found in 
	/implementation. You'll notice Compiler.cpp, BuildTokens.cpp, 
	PrintASTNodeTree.cpp, ProgramValidator.cpp, and SemanticValidator.cpp
	in the src/ directory. They serve separate purposes 
	and are thus separated. Compiler.cpp is our final cpp class containing
	all other objects and creates a TM file, BuildTokens.cpp prints the tokens
	of a valid Klein file to the screen, PrintASTNodeTree.cpp prints a formatted
	listing of tree nodes of the klein program, ProgramValidator.cpp parses the 
	klein program and outputs if it is valid or not, and SemanticValidator.cpp 
	checks to see if the klein program adheres to klein's grammar.
	
**TEST:** A directory containing all files for testing our code. This includes unit test and 
arbitrary (invalid) .kln files for further testing.
	
**PROGRAMS:** A collection of valid .kln programs we have written while building this compiler
(Also includes programs that are not ours).
	
**DOCS:** A collection of documents we've used while building this compiler. Includes language
grammer as well as any design docs.
	
**MISC:** Anything else that doesn't fit in an above directory that we feel is 
valuable for you to see!
	
  
	
## TESTING:
-----------------------------------------------------------------------------------------
We decided to use CATCH, an open source C++ testing framework that's lightweight,
IDE-independent, and fully featured. Their repo describes it as 
'A modern, C++-native, header-only, test framework for unit-tests, TDD and BDD'. Note that
the catch.h is not ours, we're just using it to test! It's a header-only framework.
We also use FakeIt, a header-only C++ mocking framework that's fully compatible with Catch.
(Again, Fakeit.hpp is not our code!)

**NOTE:** tm-cli-go.hpp was not written by us. It has been modified for unit testing purposes
as indicated by the comments at the top of the file

To run our test you can compile  
test/*.cpp and src/implementation/*.cpp into an 
executable and run it. All you need is a c++ compiler! For Example: Using a visual studio
dev console you could run 

`cl /FeRunTest /EHsc test/*.cpp src/implementation/*.cpp`

Then run the RunTest executable with `RunTest.exe` .There you have it.

ALTERNATIVELY: you can run the bash script if you have a g++ compiler and bash
Note: This is currently not compatible with STUDENT.CS.UNI.EDU due to GCC 
version differences. It does run on most other linux environments including our
TravisCI server. Run it with

`./runtest.sh`



## BUILD SCRIPTS:
-----------------------------------------------------------------------------------------
We have a build script that takes in several command line arguments. The 
file name is build_klein.sh. 

The options for build_klein.sh are

-s or --kleins:  This will build an executible file named kleins that will 
print out all tokens in a .kln file.  'kleins' takes one command line argument
which is the location relative to the current file and returns tokens for each
valid token found.

-f or --kleinf:  This will build an executable file named kleinf that will
determine if a file parses to the grammar of Klein.  'kleinf' will let the user
know if the file parses as a valid Klein file, or will return an error. 'kleinf'
takes in 1 command line argument, a .kln file location.

-p or --kleinp: This will build an executable file named kleinp that will
print the AST structure of a valid Klein program.  'kleinp' will let the user
know if an exception occurs while parsing. 'kleinp' takes in 1 command line 
argument, a .kln file location!

-v or --kleinv: This will build an executable file named kleinv that will
print the Symbol Table of a valid Klein program. 'kleinv' will let the user
know of all errors and warnings to fix with the Klein program. 'kleinv' takes 
in 1 command line argument, a .kln file!

-c or --kleinc: This will build a tm file that is named the same as the input file
with the extension ".tm". 'kleinc' will let the user know of any warnings and if
there are errors, it won't continue with code generation. 'kleinc' takes in 
1 command line argument, a klein file, with or without the .kln extension.

We have verified that this works on STUDENT.CS.UNI.EDU server.


## RESOURCES THAT MADE THIS PROJECT POSSIBLE (Descriptions as listed online):
-----------------------------------------------------------------------------------------
- [CATCH](https://github.com/philsquared/Catch): A modern, C++-native, header-only, test framework for unit-tests, TDD and BDD

- [FAKEIT](https://github.com/eranpeer/FakeIt): A simple yet very expressive, headers only library for c++ mocking. 
		
- [GIT](https://git-scm.com/): Git is a free and open source distributed version control system designed to 
		handle everything from small to very large projects with speed and efficiency
		
- [GITHUB](https://github.com/): GitHub is a web-based Git or version control repository and Internet hosting 
		service. It is mostly used for code. (wikipedia desc.)

- [TRAVIS CI](https://travis-ci.com/): Travis CI is a hosted, distributed continuous integration service used to 
		build and test software projects hosted at GitHub (wikipedia desc.)
		
- [VISUAL STUDIO](https://www.visualstudio.com/): Visual Studio is a Fully-featured integrated development 
		environment (IDE)
		for Android, iOS, Windows, web, and cloud (wikipedia desc.)

## KNOWN BUGS:
-----------------------------------------------------------------------------------------
We don't have any known bugs at this time. However:
- The FAKEIT framework is not working on the student.cs server due to the GCC version
	on student.cs.uni being 4.7, and FAKEIT needing GCC 4.8
- PrettyPrinter node structure needs to be cleaned/collapsed for easier
	reading
