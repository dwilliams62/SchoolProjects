#include <iostream> 
#include <sstream>
#include <stack>
#include <queue>

using namespace std; 

double postFixCalculator(queue<string> s);
  
int main() 
{ 
    // string input = "234 32 + 7 *";
	// Must have spaces between tokens.
 
	string input;
    cout << "Enter a postfix expression: ";
    getline(cin, input);
    
    queue<string> tokens;

    stringstream inputstream(input); 
    string token; 
    
    // Tokenizing w.r.t. space ' ' 
    while(getline(inputstream, token, ' ')) 
    {
        tokens.push(token);
    } 

    double stackValue = postFixCalculator(tokens);

    cout << "After Calculation: " << endl;
    cout << stackValue << endl;
        
}

double postFixCalculator(queue<string> s){
    stack <double> stack;
    int len = s.size();

    for (int i = 0; i < len; i++) {
        if (s.front() == "+") {
            double var1 = stack.top();
            stack.pop();
			double var2 = stack.top();
            stack.pop();
            stack.push(var1 + var2);
            s.pop();
        }
        else if (s.front() == "-") {
            double var1 = stack.top();
            stack.pop();
			double var2 = stack.top();
            stack.pop();
            stack.push(var1 - var2);
            s.pop();
        }
        else if (s.front() == "*") {
            double var1 = stack.top();
            stack.pop();
			double var2 = stack.top();
            stack.pop();
            stack.push(var1 * var2);
            s.pop();
        }
        else if (s.front() == "/") {
            double var1 = stack.top();
            stack.pop();
			double var2 = stack.top();
            stack.pop();
            stack.push(var1 / var2);
            s.pop();
        }
        else if (s.front() != " "){
            stack.push(atof(s.front().c_str()));
            s.pop();
        }
    }

    return stack.top();
}


