/*
TODO: Write a function that accepts an array of unsorted integers and returns the length of the longest consecutive sequence among them.
      (formed by integers that increae by 1)
Optimize the function so that it runs just O(N)
*/
#include <iostream>
#include <unordered_set>

using namespace std;

int longestConsecutiveInt(int arr[], int size) {
    unordered_set<int> numSet;

    //Inserts all numbers into the set
    for (int i = 0; i < size; ++i) {
        numSet.insert(arr[i]);
    }

    int longest = 0;

    //Loops through each number to find starts of sequences
    for (int i = 0; i < size; ++i) {
        int num = arr[i];

        if (numSet.find(num - 1) == numSet.end()) {
            int currentNum = num;
            int consecutives = 1;

            while (numSet.find(currentNum + 1) != numSet.end()) {
                currentNum++;
                consecutives++;
            }
            longest = max(longest, consecutives);
        }
    }
    return longest;
}

int main() {
    //Longest consecutive integers is: [2, 3, 4, 5], so return 4
    //Careful since [10, 11, 12] is consecutive integers but returns 3
    int arr1[] = {10, 5, 12, 3, 55, 30, 4, 11, 2};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    cout << "Longest Consecutive Sequence in arr1 is: " << longestConsecutiveInt(arr1, size1) << "\n";

    //Longest consecutive integers is: [11, 12, 13, 14, 15], so return 5
    int arr2[] = {19, 13, 15, 12, 18, 14, 17, 11};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    cout << "Longest Consecutive Sequence in arr2 is: " << longestConsecutiveInt(arr2, size2) << "\n";
    
    return 0;
}