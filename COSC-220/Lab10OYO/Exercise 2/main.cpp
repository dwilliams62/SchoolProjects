#include <iostream> 

using namespace std; 

int SearchRecursive(int arr[], int x, int l, int f = 0);
int SearchIterative(int arr[], int x, int l, int f = 0);
  
int main() 
{ 
    int arr[10000];
    for (int i = 0; i < 10000; i++) {arr[i] = i;}
    cout << "Enter a number to check if it's in the array and where it is: ";
    int input;
    cin >> input;
    int t1, t2;
    t2 = SearchIterative(arr, input, 10000);
    cout << "Using Iteration, it is in spot: " << t2 << endl;
    t1 = SearchRecursive(arr, input, 10000);
    cout << "Using Recursion, it is in spot: " << t1 << endl;
    return 0;
}

int SearchRecursive(int arr[], int x, int last, int first) {
    if (first <= last) {
        int middle = (first + last) / 2;
        if (arr[middle] == x) {return middle;}
        if (arr[middle] > x) {return SearchRecursive(arr, x, middle-1);}
        return SearchRecursive(arr, x, last, middle+1);
    }
    return -1;
}

int SearchIterative(int arr[], int x, int last, int first) {
    while (first <= last) {
        int middle = (first + last) / 2;
        if (arr[middle] == x) {return middle;}
        if (arr[middle] < x) {first = middle + 1;}
        else last = middle - 1;
    }
    return -1;
}