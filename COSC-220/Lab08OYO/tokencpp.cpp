#include <iostream> 
#include <sstream>

#include "ListCollection.h"

using namespace std; 
  
int main() 
{ 
    // string input = "234 32 + 7 *";
	// Must have spaces between tokens.
 
	string input;
    cout << "Enter a postfix expression: ";
    getline(cin, input);
    
    ListCollection<string> tokens; 
    stringstream inputstream(input); 
    string token; 
    
    // Tokenizing w.r.t. space ' ' 
    while(getline(inputstream, token, ' ')) 
        tokens.pushBack(token); 

    cout << "Before Calculation: " << endl;
    // Printing the token vector 
    for(int i = 0; i < tokens.size(); i++) 
        cout << tokens.getElement(i) << endl;

    tokens.postfixCalculator(tokens);

    cout << "After Calculation: " << endl;
    for(int i = 0; i < tokens.size(); i++) 
        cout << tokens.getElement(i) << endl;
}
