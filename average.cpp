#include <iostream>
using namespace std;

int main() {
    int numbers[5] = {10, 20, 30, 40, 50};
    int sum = 0;

    // Loop through the array and add each number
    for (int i = 0; i < 5; i++) {
        sum += numbers[i];
    }

    // Calculate the average
    double average = sum / 5.0;

    // Display the result
    cout << "Average: " << average << endl;

    return 0;
}
