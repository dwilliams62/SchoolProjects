#include <iostream> 
#include <stack>

using namespace std; 

bool isDelimiterBalanced(string s);
bool isMatching(char first, char last);

int main() 
{
    string input;
    cout << "Enter a string:";
    cin >> input;
    if (isDelimiterBalanced(input)) {cout << "This string is balanced!" << endl;}
    else {cout << "This string is not balanced!" << endl;}
    return 0;
}

bool isDelimiterBalanced(string s)
{
    stack<char> stack;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            stack.push(s[i]);
        }
        else if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
            if (stack.empty()) {return false;}
            else if (isMatching(stack.top(), s[i]) == false) {return false;}
            else stack.pop();
        }
    }

    return stack.empty();
}

bool isMatching(char first, char last) {
    if (first == '(' && last == ')') return true;
    else if (first == '[' && last == ']') return true;
    else if (first == '{' && last == '}') return true;

    return false;
}