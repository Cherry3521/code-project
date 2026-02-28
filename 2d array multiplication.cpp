#include <iostream>
using namespace std;

int main() {
    int a[6] = {2, 5, 7, -3, 4, 10}; // sample array
    int k = 3; // window size
    int n = 6;

    // Initial sum of first window
    int windowSum = 0;
    for(int i = 0; i < k; i++){
        windowSum += a[i];
    }

    int maxSum = windowSum;

    // Sliding window for sum
    for(int i = k; i < n; i++){
        windowSum += a[i] - a[i-k]; // slide window: add next, remove previous
        if(windowSum > maxSum) maxSum = windowSum;
    }

    cout << "Maximum sum of window: " << maxSum;
    return 0;
}

