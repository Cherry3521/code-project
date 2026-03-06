#include <iostream>
#include <vector>
using namespace std;

int main() {

    int n, m;
    cin >> n >> m;

    vector<int> basket(m+1,0);

    int mid = (m+1)/2;

    for(int ball=1; ball<=n; ball++)
    {
        int best = 1;

        for(int i=1;i<=m;i++)
        {
            if(basket[i] < basket[best])
                best = i;

            else if(basket[i] == basket[best])
            {
                if(abs(i-mid) < abs(best-mid))
                    best = i;

                else if(abs(i-mid) == abs(best-mid) && i < best)
                    best = i;
            }
        }

        basket[best]++;

        cout << best << endl;
    }

}
