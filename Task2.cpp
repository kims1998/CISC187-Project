/*
TODO: Write a function that accepts an array of distinct integers from 0, 1, 2, 3...up to N. However, the array will be
missing one integer, and your function is to return the missing one.
Optimize the function so that it can run just O(N)
*/
#include <iostream>
using namespace std;

//Calculates the sum of the array and subract it from the total sum to get the missing integer
int findMissingInt(int arr[], int size) {
    int n = size;
    int total_sum = (n * (n + 1)) / 2;

    int arr_sum = 0;
    for (int i = 0; i < size; i++) {
        arr_sum += arr[i];
    }

    return total_sum - arr_sum;
}

int main() {
    //arr1 should return 4
    int arr1[] = {2, 3, 0, 6, 1, 5};
    int size_arr1 = sizeof(arr1) / sizeof(arr1[0]);

    //arr2 should return 1
    int arr2[] = {8, 2, 3, 9, 4, 7, 5, 0, 6};
    int size_arr2 = sizeof(arr2) / sizeof(arr2[0]);

    cout << "_______________________________\nthe missing value from Arr1 is: \n" << findMissingInt(arr1, size_arr1) << "\n_______________________________\n";
    cout << "the missing value from Arr2 is: \n" << findMissingInt(arr2, size_arr2) << "\n_______________________________";

    return 0;
}