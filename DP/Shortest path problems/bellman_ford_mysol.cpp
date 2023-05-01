#include <bits/stdc++.h>
usin namespace std;

void printDist(vector<int> dist){
  cout << "{ ";
  for(auto it : dist){
    cout << it << ", ";
  }
  cout << "\b\b }\n";
}

vector<int>  bellman_ford(int V, vector<vector<int>> &edges, int source){
  vector<int> dist(V, INT_MAX);// we maintain 0 based indexing
  //assuming source node to be 1
  dist[source-1] = 0;
  for (int i = 0; i < V-1; i++) {
    for(auto it : edges){
      int u = it[0] - 1;
      int v = it[1] - 1;
      int wt = it[2];
      if(dist[u] + wt < dist[v] ) dist[v] = dist[u] + wt;
    }
    cout << "\nAfter " << i+1 << "th iteration, dist array : ";
    printDist(dist);
  }
  //in Vth iteration check if negtion cycle exists
  for(auto it : edges){
      int u = it[0] - 1;
      int v = it[1] - 1;
      int wt = it[2];
      if(dist[u] + wt < dist[v] ) return {-1};
  }
  return dist;
}

int  main(){
  int V;
  vector<vector <int>> edges;
  // edge list assumed for conveinience
  V = 7;
  edges = {
  {1, 2, 6},
  {1, 3, 5},
  {1, 4, 5},
  {2, 5, -1},
  {3, 2, -2},
  {3, 5, 1},
  {4, 3, -2},
  {4, 6, -1},
  {5, 7, 3},
  {6, 7, 3},
  };

  vector<int> dist = bellman_ford(V, edges, 1);
  cout << "FInal dist array : - ";
  printDist(dist);

  return 0;
}
