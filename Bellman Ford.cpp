#include<bits/stdc++.h>
using namespace std;

struct Edge {
  int from, to, weight;
};

vector<Edge> edges;

void bellman_ford(int n, int m, int source, int dist[]) {

  dist[source] = 0;

  for (int i = 0; i < n - 1; i++) {
    // relax all edges
    for (int j = 0; j < m; j++) {
      int u = edges[j].from;
      int v = edges[j].to;
      int w = edges[j].weight;
      if ((dist[u] != INT_MAX) && ((dist[u] + w) < dist[v])) {
        dist[v] = dist[u] + w;
      }
    }
  }

}

int main() {
  // read number of vertices and edges
  int n, m;
  cout<<"\n Bellman Ford Algorithm by Divyansh Rampal 44 "<<endl;
  cout<<"\n Enter the number of vertices the Graph : ";
  cin >> n;
  cout<<"\n Enter the number edges of the graph : ";
  cin >> m;

  int dist[n];
  for(int i = 0; i < n; i++){
    dist[i] = INT_MAX;
  }

  cout<<"\n Enter the "<<m<<" edges - "<<endl;
  // read edges
  for (int i = 0; i < m; i++) {
    cout<<"\n Enter edge "<<i + 1<<" with weight : ";
    int from, to, weight;
    cin >> from >> to >> weight;
    edges.push_back({from, to, weight});
  }

  cout<<"\n Enter the source vertex : ";
  // read source vertex
  int source;
  cin >> source;

  bellman_ford(n, m, source, dist);

  for (int i = 0; i < n; i++) {
    cout << "\n Shortest distance from " << source << " to " << i << ": " << dist[i] << endl;
  }

  return 0;
}
