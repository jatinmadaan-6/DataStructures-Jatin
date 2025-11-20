#include<bits/stdc++.h>
using namespace std;

vector<int> bfs(int start_row,int start_col , vector<vector<int>> adj)
{
  queue<pair<int,int>> q;
  q.push({start_row,start_col});
  int n = adj.size();
  int m=adj[0].size();
  vector<vector<int>> visited(n,vector<int> (m, 0));
  visited[start_row][start_col] = 1;
  vector<int> ans;


  while(!q.empty())
  {
    int row = q.front().first;
    int col = q.front().second;
    q.pop();
    ans.push_back(adj[row][col]);

    int dr[]={-1,0,1,0};
    int dc[]={0,1,0,-1};

    for(int i=0;i<4;i++)
      {
        int nr = row + dr[i];
        int nc = col +dc[i];

        if( nr>=0 && nr<n && nc>=0 && nc<m && visited[nr][nc]==0)
        {
            visited[nr][nc]=1;
            q.push({nr,nc});
        }

      }

  }
  return ans;

}

int main()
{
    vector<vector<int>> grid = {
        {10, 20, 30, 40},
        {50, 60, 70, 80},
        {90, 100, 110, 120},
        {130, 140, 150, 160}
    };
    
    int start_r = 0;
    int start_c = 0;
    vector<int> result = bfs(start_r, start_c, grid);

   
    cout << "\nBFS Traversal Order:\n";
    for (int value : result) {
        cout << value << " ";
    }
    cout << endl;


    return 0;
}