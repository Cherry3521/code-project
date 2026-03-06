#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k; // n = applicants, m = apartments, k = max allowed difference

    vector<int> applicants(n);
    vector<int> apartments(m);

    // Input desired sizes of applicants
    for(int i = 0; i < n; i++) cin >> applicants[i];

    // Input sizes of apartments
    for(int i = 0; i < m; i++) cin >> apartments[i];

    // Sort both vectors to make matching easier
    sort(applicants.begin(), applicants.end());
    sort(apartments.begin(), apartments.end());

    int i = 0;      // pointer for applicants
    int j = 0;      // pointer for apartments
    int count = 0;  // number of applicants who get an apartment

    // Loop through applicants and apartments
    while(i < n && j < m) {
        if(apartments[j] < applicants[i] - k) {
            j++; // current apartment too small → check next apartment
        }
        else if(apartments[j] > applicants[i] + k) {
            i++; // current apartment too big → next applicant
        }
        else {
            // Apartment fits the applicant
            count++;
            i++; // move to next applicant
            j++; // move to next apartment
        }
    }

    cout << count << endl; // print total matched applicants
    return 0;
}
