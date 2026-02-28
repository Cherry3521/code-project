
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int A[n];
    for (int i = 0; i < n; i++) cin >> A[i];

    for (int k = 0; k < n-1; k++) {
        int small = A[k];
        int pos = k;
        for (int j = k+1; j < n; j++) {
            if (A[j] < small) {
                small = A[j];
                pos = j;
            }
        }
        int t = A[k];
        A[k] = A[pos];
        A[pos] = t;
    }
    for (int i = 0; i < n; i++) cout << A[i] << " ";
    return 0;
}
