#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long l;
    cin >> n >> l;

    vector<long long> a(n);

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    double d = 0;

    // first gap
    d = max(d, (double)a[0]);

    // middle gaps
    for(int i = 0; i < n - 1; i++) {
        double gap = (a[i+1] - a[i]) / 2.0;
        d = max(d, gap);
    }

    // last gap
    d = max(d, (double)(l - a[n-1]));

    cout << fixed << setprecision(10) << d << endl;

    return 0;
}
