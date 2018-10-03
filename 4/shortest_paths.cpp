// shortest_paths.cpp: 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <limits>
#include <vector>
#include <queue>

using std::vector;
using std::queue;
using std::pair;
using std::priority_queue;
using namespace std;

void relax(vector<vector<int> > &adj, vector<vector<int> > &cost,
	vector<long long> &dis, int u, int v, int w, vector<int> &reachable) {
	if (dis[u] != numeric_limits<long long>::max() && dis[v] > dis[u] + cost[u][w]) {
		dis[v] = dis[u] + cost[u][w];
		reachable[v] = 1;
	}
}

void bellmanFord(vector<vector<int> > &adj, vector<vector<int> > &cost,
	vector<long long> &dis, vector<int> &reachable, vector<int> &shortest) {
	queue<int> shortestQueue;
	for (size_t i = 0; i < adj.size() - 1; i++) {
		for (size_t u = 0; u < adj.size(); u++) {
			for (size_t v = 0; v < adj[u].size(); v++) {
				relax(adj, cost, dis, u, adj[u][v], v, reachable);
			}
		}
	}
	for (size_t u = 0; u < adj.size(); u++) {
		for (size_t v = 0; v < adj[u].size(); v++) {
			if (dis[u] != numeric_limits<long long>::max() && dis[adj[u][v]] > dis[u] + cost[u][v]) {
				shortestQueue.push(adj[u][v]);
			}
		}
	}
	while (!shortestQueue.empty()) {
		shortest[shortestQueue.front()] = 0;
		for (size_t v = 0; v < adj[shortestQueue.front()].size(); v++) {
			if (shortest[adj[shortestQueue.front()][v]] == 1) {
				shortestQueue.push(adj[shortestQueue.front()][v]);
			}
		}
		shortestQueue.pop();
	}
}

void shortest_paths(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, vector<long long> &distance, vector<int> &reachable, vector<int> &shortest) {
	//write your code here
	distance[s] = 0;
	reachable[s] = 1;
	bellmanFord(adj, cost, distance, reachable, shortest);

}

int main() {
	int n, m, s;
	std::cin >> n >> m;
	vector<vector<int> > adj(n, vector<int>());
	vector<vector<int> > cost(n, vector<int>());
	for (int i = 0; i < m; i++) {
		int x, y, w;
		std::cin >> x >> y >> w;
		adj[x - 1].push_back(y - 1);
		cost[x - 1].push_back(w);
	}
	std::cin >> s;
	s--;
	vector<long long> distance(n, std::numeric_limits<long long>::max());
	vector<int> reachable(n, 0);
	vector<int> shortest(n, 1);
	shortest_paths(adj, cost, s, distance, reachable, shortest);
	for (int i = 0; i < n; i++) {
		if (!reachable[i]) {
			std::cout << "*\n";
		}
		else if (!shortest[i]) {
			std::cout << "-\n";
		}
		else {
			std::cout << distance[i] << "\n";
		}
	}
	//system("pause");

}
