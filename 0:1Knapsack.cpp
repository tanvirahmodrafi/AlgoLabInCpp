#include <iostream>
#include <algorithm>
using namespace std;

int knapsack(int capacity, int weights[], int values[], int n) {
    int dp[n + 1][capacity + 1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= capacity; j++) {
            if (j == 0 || i == 0) {
                dp[i][j] = 0;
            } else if (weights[i - 1] <= j) {
                dp[i][j] = max(values[i - 1] + dp[i - 1][j - weights[i - 1]], dp[i - 1][j]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    int i = n,w = capacity;
    while(i>0 && w>0){
        if(dp[i][w] != dp[i-1][w]){
            cout<< "item "<<weights[i-1]<<" values "<<values[i-1]<<endl;
            w -= weights[i-1];
        }else{
            i--;
        }
    }
    return dp[n][capacity];
}

int main()
{
    int weights[] = {2, 3, 4, 5};
    int values[] = {1, 2, 5, 6};
    int capacity = 8;
    int n = sizeof(values) / sizeof(values[0]);

    cout << '\n'
         << knapsack(capacity, weights, values, n) << endl;

    return 0;
}
