/*
TODO: Write a function that sorts these temperature readings from lowest to highest
Optimize the function so that its faster than O(NlogN), most likely O(N) multiplied by some constant
*/
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

//Sorts the temperature by multiplying each temp by 10 to convert each value into an integer using static_cast
//OFFSET and MAX_TEMP are based on the lowest/highest temperatures given from the array
void sortTemp(vector<double>& arr) {
    const int OFFSET = 970;
    const int MAX_TEMP = 990;
    const int RANGE = MAX_TEMP - OFFSET + 1;

    vector<vector<double>> buckets(RANGE);

    //Places each element into appropriate bucket, which perserves the order
    for (double temp : arr) {
        int index = static_cast<int> (temp * 10 + 0.5);
        buckets[index - OFFSET].push_back(temp);
    }

    //Prints out the sorted Temperatures
    cout << "The Sorted Temperatures:\n";
    for (int i = 0; i < RANGE; ++i) {
        for  (double temp : buckets[i]) {
            cout << "| " << fixed << setprecision(1) << (i + OFFSET) / 10.0 << " |";
        }
    }
    cout << endl;
}

int main() {
    //Should return [97.1, 97.1, 97.8, 98.0, 98.0, 98.2, 98.5, 98.6, 98.9, 99.0]
    vector<double> arr = {98.6, 98.0, 97.1, 99.0, 98.9, 97.8, 98.5, 98.2, 98.0, 97.1};
    sortTemp(arr);

    return 0;
}