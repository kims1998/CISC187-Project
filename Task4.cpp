/*
TODO: Write a function that accepts an array of numbers and computes the highest product of any TWO numbers in the array
Optimize the function so that it can run just O(N)
*/
#include <iostream>
using namespace std;

//Function that calculates and returns the highest product of two numbers
int highestProduct(int arr[], int size) {
    int max1 = arr[0] > arr[1] ? arr[0] : arr[1];
    int max2 = arr[0] > arr[1] ? arr[1] : arr[0];

    int min1 = arr[0] < arr[1] ? arr[0] : arr[1];
    int min2 = arr[0] < arr[1] ? arr[1] : arr[0];

    for (int i = 2; i < size; i++) {
        int num = arr[i];

        //Updates the Highest Max Values
        if (num > max1) {
            max2 = max1;
            max1 = num;
        } else if (num > max2) {
            max2 = num;
        }

        //Updates the Lowest Min Values
        if (num < min1) {
            min2 = min1;
            min1 = num;
        } else if (num < min2) {
            min2 = num;
        }
    }
    return max(max1 * max2, min1 * min2);
}

int main() {
    //(-10) * (-6) = 60, which should be the highest product of any two numbers
    int arr[] = {5, -10, -6, 9, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "The highest product is: " << highestProduct(arr, size);

    return 0;
}