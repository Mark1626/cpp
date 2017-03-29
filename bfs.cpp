// Small demonstration of BFS to calculate the number of edges each node has
#include <iostream>
#include <vector>
#include <queue>

const int limit = 10;

using namespace std;

vector <int> adj[limit+1];
vector <bool> visited;
vector <int> edges;

//Standard template for BFS can be modified to be used in multiple problems
void BFS(int root) {

  queue<int> Q;
  Q.push(root);

  visited[root] = true;

  while(!Q.empty()) {

    int x = Q.front();
    Q.pop();

    for(int i=0; i < adj[x].size(); ++i) {

      //Calulate the number of edges here
      edges[x]++;

      if(!visited[adj[x][i]]) {
        visited[adj[x][i]] = true;
        Q.push(adj[x][i]);
      }
    }
  }
}

int main() {
	
  int n,t;
  cin>>n>>t;
  visited.assign(n+1, false);
  edges.assign(n+1, 0);

  int x, y;

  while(t--) {
    cin>>x>>y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  BFS(1);

  for(int i=1;i <= n; ++i)
    cout<<edges[i]<<" ";
  cout<<endl;

	return 0;
}