// bfs.cpp: 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Vertex {
	int num;
	bool visited = false;
	int distance = -1;
	vector<int> adj;
};

void BFS(vector<Vertex> &vertex, int s) {
	vertex[s].visited = true;
	vertex[s].distance = 0;
	queue<int> vertexNum;
	int u, v;
	vertexNum.push(s);
	while (!vertexNum.empty()) {
		u = vertexNum.front();
		vertexNum.pop();
		for (size_t i = 0; i < vertex[u].adj.size(); i++) {
			v = vertex[u].adj[i];
			if (vertex[v].visited == false) {
				vertex[v].visited = true;
				vertex[v].distance = vertex[u].distance + 1;
				vertexNum.push(v);
			}
		}
	}
}

int distance(vector<Vertex> &vertex, int s, int t) {
	//write your code here
	BFS(vertex, s);
	return vertex[t].distance;
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<Vertex> vertex(n);

	for (size_t i = 0; i < n; i++) {
		vertex[i].num = i + 1;
		//vertex[i].distance = m + 1;
	}

	for (size_t i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		vertex[x - 1].adj.push_back(y - 1);
		vertex[y - 1].adj.push_back(x - 1);
	}

	int s, t;
	cin >> s >> t;
	s--, t--;
	cout << distance(vertex, s, t);
	//system("pause");
}
