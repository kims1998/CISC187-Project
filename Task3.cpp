/*
TODO: Write a function that returns the most profit from one purchase (buy and sell)
Optimize the function so that it can run just O(N)
*/
#include <iostream>
using namespace std;

int maxProfit(int price[], int size) {
    //Profit is made only when there exists 2 prices
    if (size < 2) return 0;

    int min_price = price[0];
    int max_profit = price[1] - price[0];

    for (int i = 0; i < size; ++i) {
        int curr_price = price[i];
        int potential_profit = curr_price - min_price;

        max_profit = max(max_profit, potential_profit);
        min_price = min(min_price, curr_price);
    }
    return max(max_profit, 0);
}

int main() {
    //Buy on $5 and sell on $11 yields the highest profit of $6
    int arr[] = {10, 7, 5, 8, 11, 2, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    int profit = maxProfit(arr, size);
    cout << "Maximum Profit through one transaction is: $" << profit;

    return 0;
}