#include<bits/stdc++.h>

using namespace std;

class Solution {
  public:

    int find(int node, vector<int>& parent){

        if(node == parent[node])
            return node;

        return parent[node] = find(parent[node], parent);
    }

    void Union(int x, int y, vector<int>& parent){

        int parent_x = find(x, parent);
        int parent_y = find(y, parent);

        if(parent_x == parent_y)
            return;

        parent[parent_x] = parent_y;
    }

    static bool comparator(const vector<int>& a, const vector<int>& b){

        return a[2] < b[2];
    }

    int kruskalsMST(int V, vector<vector<int>> &edges) {

        vector<int> parent(V);

        for(int i = 0; i < V; i++){
            parent[i] = i;
        }

        sort(edges.begin(), edges.end(), comparator);

        int sum = 0;

        for(auto edge : edges){

            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            if(find(u, parent) != find(v, parent)){

                sum += w;

                Union(u, v, parent);
            }
        }

        return sum;
    }
};

int main() {

    Solution obj;

    vector<vector<int>> edges = {
        {0,1,10},
        {0,2,6},
        {0,3,5},
        {1,3,15},
        {2,3,4}
    };

    int V = 4;

    cout << obj.kruskalsMST(V, edges);

    return 0;
}
