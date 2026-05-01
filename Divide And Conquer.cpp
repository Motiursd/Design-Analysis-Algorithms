#include <bits/stdc++.h>
using namespace std;



int maxCrossingSum(int arr[], int l, int m, int r) {
    int sum = 0;
    int leftSum = INT_MIN;

    for (int i = m; i >= l; i--) {
        sum += arr[i];
        leftSum = max(leftSum, sum);
    }

    sum = 0;
    int rightSum = INT_MIN;

    for (int i = m + 1; i <= r; i++) {
        sum += arr[i];
        rightSum = max(rightSum, sum);
    }

    return leftSum + rightSum;
}

int maxSubArray(int arr[], int l, int r) {
    if (l == r)
        return arr[l];

    int m = (l + r) / 2;

    return max({
        maxSubArray(arr, l, m),
        maxSubArray(arr, m + 1, r),
        maxCrossingSum(arr, l, m, r)
    });
}

int main() {
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Maximum Subarray Sum = " 
         << maxSubArray(arr, 0, n - 1);

    return 0;
}
