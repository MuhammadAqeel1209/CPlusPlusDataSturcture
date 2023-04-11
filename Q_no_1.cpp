#include<iostream>
using namespace std;

int CalculateFactorial(int number); //--> Declaration

int main()
{
    //Varaible
    int num;
    //inuputs
    cout << "Enter the number for factorial\t";
    cin >> num;

    //Calling Function
    cout << "Factorial of " << num << " is \t" << CalculateFactorial(num) << endl;
}

int CalculateFactorial(int number) // --Defination
{
    int factorial = 1;
    for (int i = number ; i >= 1; i--)
    {
        factorial = factorial * i;
    }
    return factorial;
}