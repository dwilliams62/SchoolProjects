#include <iostream> 
#include <sstream>

using namespace std; 

long BinaryFib(long n);
long LinearFib(long n, long a = 0, long b = 1);
long IterativeFib(long n);
  
int main() 
{ 
    cout << "Enter a number to find a fibonacchi number: ";
    long input, bf, lf, f;
    cin >> input;

    //this one takes forever, over a full minute
    bf = BinaryFib(input);
    cout << "Using a binary method, the fibonacchi number is: " << bf << endl;

    //this one takes very little time
    lf = LinearFib(input);
    cout << "Using a linear method, the fibonacchi number is: " << lf << endl;

    //also takes very little time
    f = IterativeFib(input);
    cout << "Using a iterative method, the fibonacchi number is: " << f << endl;
    return 0;
}

long BinaryFib(long n) {
    if (n <= 1) {return n;}
    return BinaryFib(n-1) + BinaryFib(n-2);
}

long LinearFib(long n, long a, long b) {
    if (n==0) return a;
    if (n==1) return b;
    return LinearFib(n-1, b, a+b);
}

long IterativeFib(long n) {
    long a = 0, b = 1, c, i;
    if (n==0) return a;
    for (i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}