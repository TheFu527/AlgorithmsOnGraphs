// acyclicity.cpp: 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

struct Vertex {
	int num;
	bool visited = false;
	vector<int> adj;
	int preClock;
	int postClock;
};

vector<int> listOfSort;

void explore(vector<Vertex> &vertex, int v, int &clock) {
	vertex[v].visited = true;
	clock++;
	vertex[v].preClock = clock;
	for (int i = 0; i < vertex[v].adj.size(); i++) {
		if (vertex[vertex[v].adj[i]].visited == false) {
			explore(vertex, vertex[v].adj[i], clock);
		}
	}
	clock++;
	vertex[v].postClock = clock;
	listOfSort.push_back(vertex[v].num);
}

void DFS(vector<Vertex> &vertex) {
	int clock = 0;
	for (int i = 0; i < vertex.size(); i++) {
		if (vertex[i].visited == false) {
			explore(vertex, i, clock);
		}
	}
}

void acyclic(vector<Vertex> &vertex) {
	//write your code here
	DFS(vertex);
	for (int i = listOfSort.size() - 1; i >= 0; i--)
		cout << listOfSort[i] << " ";
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

	//system("pause");
}
