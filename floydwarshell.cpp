#include<bits/stdc++.h>

using namespace std;

class Solution {
  public:

    void floydWarshall(vector<vector<int>> &dist) {

        int v = dist.size();

        for(int via = 0; via < v; via++) {

            for(int i = 0; i < v; i++) {

                for(int j = 0; j < v; j++) {

                    if(dist[i][via] != 100000000 &&
                       dist[via][j] != 100000000) {

                        dist[i][j] = min(dist[i][j],
                                         dist[i][via] + dist[via][j]);
                    }
                }
            }
        }
    }
};

int main() {

    Solution obj;

    vector<vector<int>> dist = {

        {0, 3, 100000000, 7},
        {8, 0, 2, 100000000},
        {5, 100000000, 0, 1},
        {2, 100000000, 100000000, 0}
    };

    obj.floydWarshall(dist);

    cout << "Shortest distance matrix:\n\n";

    for(int i = 0; i < dist.size(); i++) {

        for(int j = 0; j < dist.size(); j++) {

            if(dist[i][j] == 100000000)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}
