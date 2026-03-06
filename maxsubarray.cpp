#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];

    long long current_sum = arr[0];
    long long max_sum = arr[0];

    for(int i=1; i<n; i++){
        // Decide: extend current subarray or start new
        current_sum = max(arr[i], current_sum + arr[i]);
        max_sum = max(max_sum, current_sum); // update overall max
    }

    cout << max_sum << endl;

    return 0;
}
