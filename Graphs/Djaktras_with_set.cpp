#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int n, vector<vector<pair<int,int>>> &adj, int src) {
    const int INF = 1e9;
    vector<int> dist(n, INF);

    
    set<pair<int,int>> st;

    dist[src] = 0;
    st.insert({0, src});

    while(!st.empty()) {
        auto it = st.begin();       
        int distance = it->first;
        int node = it->second;
        st.erase(it);

       
        for(auto edge : adj[node]) {
            int v = edge.first;
            int w = edge.second;

            if(distance + w < dist[v]) {

               
                if(dist[v] != INF) {
                    st.erase({dist[v], v});
                }

                dist[v] = distance + w;
                st.insert({dist[v], v});
            }
        }
    }

    return dist;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int,int>>> adj(n);

    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});  
    }

    int src;
    cin >> src;

    vector<int> dist = dijkstra(n, adj, src);

    for(int i = 0; i < n; i++) {
        cout << "Distance to " << i << " = " << dist[i] << "\n";
    }
}
