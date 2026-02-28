#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int A[n];
    for (int i = 0; i < n; i++) cin >> A[i];

    for (int k = 1; k < n; k++) {
        int temp = A[k];
        int j = k - 1;
        while (j >= 0 && temp < A[j]) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = temp;
    }

    for (int i = 0; i < n; i++) cout << A[i] << " ";
    return 0;
}
