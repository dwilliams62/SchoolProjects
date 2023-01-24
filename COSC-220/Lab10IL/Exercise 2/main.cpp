#include <iostream> 
#include <sstream>

using namespace std; 

bool isPal(const string& str, int startIndex, int endIndex);
  
int main() 
{ 
    string input;
    cout << "Enter a string, no spaces and all in lower case: ";
    cin >> input;
    
    if (isPal(input, 0, input.length() - 1)) {
        cout << input << " is a palindrome." << endl;
    }
    else {
        cout << input << " is not a palindrome." << endl;
    }
    return 0;
}

bool isPal(const string& str, int startIndex, int endIndex) {
    if (startIndex >= endIndex) return true;
    if (str[startIndex] == str[endIndex]) {
        startIndex++;
        endIndex--;
        isPal(str, startIndex, endIndex);
    }
    else return false;
}