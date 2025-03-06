#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> create_AdjMatrix(int n, int m) {
    vector<vector<int>> adj(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    return adj;
}

vector<vector<int>> create_AdjList(int n, int m) {
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    return adj;
}

int main(){
	int n, m;
	cin>> n>> m;
	/*
	Create the graph here
	*/
	return 0;
}