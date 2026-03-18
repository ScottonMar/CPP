#include <iostream>
using namespace std;

int main() {
    // Declare variables
    double num1, num2;

    // Get input from the user
    cout << "Enter the first number: ";
    cin >> num1;

    cout << "Enter the second number: ";
    cin >> num2;

    // Perform calculations
    double addition = num1 + num2;
    double subtraction = num1 - num2;
    double multiplication = num1 * num2;
    double division = num1 / num2;

    // Display results
    cout << "\n--- Calculator Results ---" << endl;
    cout << "Addition: " << addition << endl;
    cout << "Subtraction: " << subtraction << endl;
    cout << "Multiplication: " << multiplication << endl;
    cout << "Division: " << division << endl;

    return 0;
}
