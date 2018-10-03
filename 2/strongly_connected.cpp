// strongly_connected.cpp: 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <algorithm>
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

vector<int> postorder;

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
	postorder.push_back(vertex[v].num);
}

void exploreWithoutClock(vector<Vertex> &vertex, int v) {
	vertex[v].visited = true;
	for (int i = 0; i < vertex[v].adj.size(); i++) {
		if (vertex[vertex[v].adj[i]].visited == false) {
			exploreWithoutClock(vertex, vertex[v].adj[i]);
		}
	}
}

void DFS(vector<Vertex> &vertex) {
	int clock = 0;
	for (int i = 0; i < vertex.size(); i++) {
		if (vertex[i].visited == false) {
			explore(vertex, i, clock);
		}
	}
}

int number_of_strongly_connected_components(vector<Vertex> &vertex, vector<Vertex> &vertexR) {
	int result = 0;
	//write your code here
	DFS(vertexR);
	for (int i = postorder.size() - 1; i >= 0; i--) {
		if (vertex[postorder[i]-1].visited == false) {
			exploreWithoutClock(vertex, postorder[i]-1);
			result++;
		}
	}
	return result;
}

int main() {
	size_t n, m;
	cin >> n >> m;
	vector<Vertex> vertex(n);
	vector<Vertex> vertexR(n);
	for (size_t i = 0; i < n; i++) {
		vertex[i].num = i + 1;
		vertexR[i].num = i + 1;
	}

	for (size_t i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		vertex[x - 1].adj.push_back(y - 1);
		vertexR[y - 1].adj.push_back(x - 1);
	}
	cout << number_of_strongly_connected_components(vertex, vertexR);
	//system("pause");
}
