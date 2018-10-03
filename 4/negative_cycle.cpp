// negative_cycle.cpp: 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include<functional>

#define MAXINT 2000000000

using namespace std;

void relax(vector<vector<int> > &adj, vector<vector<int> > &cost,
	vector<int> &dis, int u, int v, int w) {
	if (dis[v] > dis[u] + cost[u][w]) {
		dis[v] = dis[u] + cost[u][w];
	}
}

bool bellmanFord(vector<vector<int> > &adj, vector<vector<int> > &cost,
	vector<int> &dis) {
	for (size_t i = 0; i < adj.size() - 1; i++) {
		for (size_t u = 0; u < adj.size(); u++) {
			for (size_t v = 0; v < adj[u].size(); v++) {
				relax(adj, cost, dis, u, adj[u][v], v);
			}
		}
	}
	for (size_t u = 0; u < adj.size(); u++) {
		for (size_t v = 0; v < adj[u].size(); v++) {
			if (dis[adj[u][v]] > dis[u] + cost[u][v]) {
				return true;
			}
		}
	}
	return false;
}

int negative_cycle(vector<vector<int> > &adj, vector<vector<int> > &cost) {
	//write your code here
	vector<int> dis(adj.size(), MAXINT);
	vector<int> prev(adj.size(), -1);
	dis[0] = 0;
	return (int)bellmanFord(adj,cost,dis);
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int> > adj(n, vector<int>());
	vector<vector<int> > cost(n, vector<int>());
	for (int i = 0; i < m; i++) {  
		int x, y, w;
		cin >> x >> y >> w;
		adj[x - 1].push_back(y - 1); 
		cost[x - 1].push_back(w);
	}
	cout << negative_cycle(adj, cost);
	//system("pause");
}
