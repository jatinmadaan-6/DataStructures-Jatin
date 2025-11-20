#include<bits/stdc++.h>
using namespace std;

void dfs_u(int u,vector<vector<int>> adj, vector<int>& ans,vector<bool>& visited)
{
   ans.push_back(u);
   visited[u]=true;

   for (int v : adj[u]) {
        if (!visited[v]) {
          
            dfs_u(v, adj, ans, visited);
        }
    }

}

vector<int> dfs(int start,vector<vector<int>> adj)
{
    int n = adj.size();
    vector<bool> visited(n,false);
    vector<int> ans;

    dfs_u(start,adj, ans,visited);

    return ans;

    
}


int main()
{

    const int V = 5;

   
    vector<vector<int>> adj(V);

    
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(0);
    adj[1].push_back(3);    
    adj[2].push_back(0);
    adj[2].push_back(3); 
    adj[3].push_back(1);
    adj[3].push_back(2);
    adj[3].push_back(4);
    adj[4].push_back(3);

    int start_node = 0;


   
    vector<int> dfs_result = dfs(start_node, adj);

    for (int node : dfs_result) {
        cout << node << " ";
    }
    cout << endl;
    
}