#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent, rank;

    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for(int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]); 
    }

    bool unite(int x, int y) {
        x = find(x);
        y = find(y);
        if(x == y) return false;

      
        if(rank[x] < rank[y]) swap(x, y);

        parent[y] = x;
        if(rank[x] == rank[y]) rank[x]++;

        return true;
    }
};

struct Edge {
    int u, v, w;
};

int main() {
    int n, m;
    cin >> n >> m;  // n nodes, m edges

    vector<Edge> edges(m);

    for(int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    // sort edges by weight
    sort(edges.begin(), edges.end(), [](Edge &a, Edge &b){
        return a.w < b.w;
    });

    DSU dsu(n);

    int mst_weight = 0;
    vector<Edge> mst_edges;

    for(auto &e : edges) {
        if(dsu.unite(e.u, e.v)) {  // if no cycle
            mst_weight += e.w;
            mst_edges.push_back(e);
        }
    }

    cout << "MST Weight = " << mst_weight << "\n";
    cout << "Edges in MST:\n";
    for(auto &e : mst_edges) {
        cout << e.u << " - " << e.v << " weight " << e.w << "\n";
    }

    return 0;
}
