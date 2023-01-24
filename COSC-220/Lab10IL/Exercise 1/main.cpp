#include <iostream> 
#include <sstream>

using namespace std; 

int NChooseK(int n, int k);
  
int main() 
{ 
    string input;
	int n, k;
    cout << "Enter n and k (integer) with a space between them: ";
    getline(cin, input);
    stringstream ss(input);
    ss >> n;
    ss >> k;
    
    cout << n << " choose " << k << " = " << NChooseK(n,k) << endl;
    return 0;
}

int NChooseK(int n, int k) {
    if (n == 0 || k == 0) return 1;
    else if (n == k) return 1;
    else if (k > n || n < 0 || k < 0) return 0;
    else return NChooseK(n-1, k-1) + NChooseK(n-1, k);
}