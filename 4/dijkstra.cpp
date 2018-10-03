// dijkstra.cpp: 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include<functional>
#include <map>

#define MAXINT 2147483647

using namespace std;

/*
void initializeSingleSource(vector<vector<int> > &adj, 
	vector<vector<int> > &cost, vector<int> &dis, int s) {
	for (size_t i = 0; i < adj.size(); i++) {
		dis[i] = 0;
	}
}
*/

void relax(vector<vector<int> > &adj, vector<vector<int> > &cost, 
	vector<int> &dis, int u, int v, int w, priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > &H) {
	if (dis[v] > dis[u] + cost[u][w]) {
		dis[v] = dis[u] + cost[u][w];
		H.push(make_pair(dis[v], v));
	}
}

void dijkstra(vector<vector<int> > &adj, vector<vector<int> > &cost,
	vector<int> &dis, int s, int t) {
	//map<int, int> H;
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int,int> > > H;
	H.push(make_pair(dis[s], s));
	while (!H.empty()) {
		int u;
		u = H.top().second;
		H.pop();
		for (size_t i = 0; i < adj[u].size(); i++) {
			relax(adj, cost, dis, u, adj[u][i], i, H);
		}
	}
}

int distance(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, int t) {
	//write your code her
	vector<int> dis(adj.size(), MAXINT);
	vector<int> prev(adj.size(), -1);
	dis[s] = 0;
	dijkstra(adj, cost, dis, s, t);
	if (dis[t] == MAXINT)
		return -1;
	else return dis[t];
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
	int s, t;
	cin >> s >> t;
	s--, t--;
	cout << distance(adj, cost, s, t);
	//system("pause");
}
