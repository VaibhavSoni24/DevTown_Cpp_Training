#include<iostream>
using namespace std;
int main() {
    char operation;
    float a, b, c;
    cout << "Enter an operation you want to perform (<+, -, *, />): ";
    cin >> operation;
    cout << "Enter the first operand: ";
    cin >> a;
    cout << "Enter the second operand: ";
    cin >> b;
    switch(operation)
    {
        case '+':
            c = a + b;
            cout << "The addition is " << c << "." << endl;
            break;
        case '-':
            c = a - b;
            cout << "The subtraction is " << c << "." << endl;
            break;
        case '*':
            c = a * b;
            cout << "The multiplication is " << c << "." << endl;
            break;
        case '/':
            if (b != 0)
            {
                c = a / b;
                cout << "The division is " << c << "." << endl;
            }
            else
            {
                cout << "Error! Division by zero." << endl;
            }
            break;
        default:
            cout << "You did not enter a valid operation!" << endl;
    }
    return 0;
}