// reachability.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

void explore(vector<vector<int> > &adj, int x, vector<bool> &visited) {
	visited[x] = true;
	for (int i = 0; i < adj[x].size(); i++) {
		if (visited[adj[x][i]] == false) {
			explore(adj, adj[x][i], visited);
		}
	}
}


int reach(vector<vector<int> > &adj, int x, int y, vector<bool> &visited) {
	//write your code here
	explore(adj, x, visited);
	return (int)visited[y];
}

int main() {
	size_t n, m;
	cin >> n >> m;
	vector<vector<int> > adj(n, vector<int>());
	vector<bool> visited(n, false);
	for (size_t i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		adj[x - 1].push_back(y - 1);
		adj[y - 1].push_back(x - 1);
	}
	int x, y;
	cin >> x >> y;
	cout << reach(adj, x - 1, y - 1, visited);
	system("pause");
}
