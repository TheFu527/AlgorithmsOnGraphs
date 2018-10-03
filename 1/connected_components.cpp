// connected_components.cpp: 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

void explore(vector<vector<int> > &adj, int v, vector<bool> &visited) {
	visited[v] = true;
	for (int i = 0; i < adj[v].size(); i++) {
		if (visited[adj[v][i]] == false) {
			explore(adj, adj[v][i], visited);
		}
	}
}

int DFS(vector<vector<int> > &adj) {
	int cc = 1;
	vector<bool> visited(adj.size(), false);
	for (int i = 0; i < adj.size(); i++) {
		if (visited[i] == false) {
			explore(adj, i, visited);
			cc++;
		}
	}
	return cc - 1;
}

int number_of_components(vector<vector<int> > &adj) {
	int res = 0;
	//write your code here
	res = DFS(adj);
	return res;
}

int main() {
	size_t n, m;
	cin >> n >> m;
	vector<vector<int> > adj(n, vector<int>());
	for (size_t i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		adj[x - 1].push_back(y - 1);
		adj[y - 1].push_back(x - 1);
	}
	cout << number_of_components(adj);
	//system("pause");
}
