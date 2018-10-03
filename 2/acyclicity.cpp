// acyclicity.cpp: 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

struct Vertex {
	int num;
	string color = "white";
	bool visited = false;
	vector<int> adj;
	int preClock;
	int postClock;
};

bool hasCycle;

void explore(vector<Vertex> &vertex, int v, int &clock) {
	vertex[v].color = "gray";
	clock++;
	vertex[v].preClock = clock;
	for (int i = 0; i < vertex[v].adj.size(); i++) {
		if (vertex[vertex[v].adj[i]].color == "white") {
			explore(vertex, vertex[v].adj[i], clock);
		}
		else if (vertex[vertex[v].adj[i]].color == "gray") {
			hasCycle = true;
			return;
		}
	}
	vertex[v].color = "black";
	clock++;
	vertex[v].postClock = clock;
}

void DFS(vector<Vertex> &vertex) {
	int clock = 0;
	for (int i = 0; i < vertex.size(); i++) {
		if (vertex[i].color == "white") {
			explore(vertex, i, clock);
			if (hasCycle == true)
				return;
		}
	}
}

void acyclic(vector<Vertex> &vertex) {
	//write your code here
	hasCycle = false;
	DFS(vertex);
}

int main() {
	size_t n, m;
	cin >> n >> m;
	vector<Vertex> vertex(n);

	for (size_t i = 0; i < n; i++) {
		vertex[i].num = i + 1;
	}

	for (size_t i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		vertex[x - 1].adj.push_back(y - 1);
	}
	acyclic(vertex);
	cout << (int)hasCycle;
	//system("pause");
}
