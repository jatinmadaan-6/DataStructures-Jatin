#include <bits/stdc++.h>
using namespace std;

void primMST(int n, vector<vector<pair<int,int>>>& graph) {
    vector<int> key(n, INT_MAX);    
    vector<int> parent(n, -1);      
    vector<bool> inMST(n, false);

  
    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    key[0] = 0;
    pq.push({0, 0});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (inMST[u]) continue;
        inMST[u] = true;

        // all adjacent edges
        for (auto &x : graph[u]) {
            int wt = x.first;
            int v = x.second;

            if (!inMST[v] && wt < key[v]) {
                key[v] = wt;
                parent[v] = u;
                pq.push({key[v], v});
            }
        }
    }

    
    int totalWeight = 0;

    cout << "Edges in MST:\n";
    for (int i = 1; i < n; i++) {
        cout << parent[i] << " - " << i 
             << " weight = " << key[i] << ")\n";
        totalWeight += key[i];
    }

    cout << "\nTotal MST Weight = " << totalWeight << endl;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int,int>>> graph(n);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({w, v});
        graph[v].push_back({w, u});
    }

    primMST(n, graph);
    return 0;
}
