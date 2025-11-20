#include <bits/stdc++.h>
using namespace std;

void dijkstra(int n, vector<vector<pair<int,int>>> &adj, int src) {
    const int INF = 1e9;
    vector<int> dist(n, INF);

  
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while(!pq.empty()) {
        int distance = pq.top().first;
        int node = pq.top().second;
        pq.pop();

       
        if(distance != dist[node]) 
            continue;

      
        for(auto edges : adj[node]) {
            int v = edges.first; 
            int w = edges.second;

            if(dist[node] + w < dist[v]) {
                dist[v] = dist[node] + w;
                pq.push({dist[v], v});
            }
        }
    }

  
    for(int i = 0; i < n; i++) {
        cout << "Distance to node " << i << " = " << dist[i] << "\n";
    }
}

int main() {
    int n, m;
    cin >> n >> m;  // n = vertices, m = edges

    vector<vector<pair<int,int>>> adj(n);

    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});  
    }

    int src;
    cin >> src;

    dijkstra(n, adj, src);
    return 0;
}
