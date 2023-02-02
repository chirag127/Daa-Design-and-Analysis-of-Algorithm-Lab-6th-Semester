
#include<bits/stdc++.h>
using namespace std;

bool subset_sum(int arr[], int n, int sum) {
    if (sum == 0) return true;
    if (n == 0 && sum != 0) return false;

    if (arr[n-1] > sum)
        return subset_sum(arr, n-1, sum);

    return subset_sum(arr, n-1, sum) ||
           subset_sum(arr, n-1, sum-arr[n-1]);
}

int main() {
    int arr[] = {3, 34, 4, 12, 5, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum = 9;
    if (subset_sum(arr, n, sum) == true)
        cout << "Found a subset with given sum" << endl;
    else
        cout << "No subset with given sum" << endl;
    return 0;
}
```
