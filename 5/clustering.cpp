// clustering.cpp: 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <vector>
#include <cmath>
#include <queue>
#include <functional>

using namespace std;

void makeSet(int i, vector<int> &parent, vector<int> &rank) {
	parent[i] = i;
	rank[i] = 0;
}

int findSet(int i, vector<int> &parent) {
	while (i != parent[i]) {
		i = parent[i];
	}
	return i;
}

void unionSet(int i, int j, vector<int> &parent, vector<int> &rank) {
	int i_id = findSet(i, parent);
	int j_id = findSet(j, parent);
	if (i_id == j_id) {
		return;
	}
	if (rank[i_id] > rank[j_id]) {
		parent[j_id] = i_id;
	}
	else {
		parent[i_id] = j_id;
		if (rank[i_id] == rank[j_id]) {
			rank[j_id]++;
		}
	}
}

double dis(vector<int> &x, vector<int> &y, int v, int z) {
	return sqrt((x[v] - x[z])*(x[v] - x[z]) + (y[v] - y[z])*(y[v] - y[z]));
}

double mstKruskal(vector<int> &x, vector<int> &y, int k) {
	vector<int> parent(x.size());
	vector<int> rank(x.size());
	int setNum = x.size();
	for (size_t i = 0; i < x.size(); i++) {
		makeSet(i, parent, rank);
	}
	priority_queue<pair<double, pair<int, int> >, vector<pair<double, pair<int, int> > >, greater<pair<double, pair<int, int> > > > prioQ;
	for (size_t i = 0; i < x.size(); i++)
		for (size_t j = i + 1; j < x.size(); j++) {
			prioQ.push(make_pair(dis(x, y, i, j), make_pair(i, j)));
		}
	while (setNum > k) {
		int u = prioQ.top().second.first;
		int v = prioQ.top().second.second;
		prioQ.pop();
		if (findSet(u, parent) != findSet(v, parent)) {
			unionSet(u, v, parent, rank);
			setNum--;
		}
	}
	while (!prioQ.empty()) {
		int u = prioQ.top().second.first;
		int v = prioQ.top().second.second;
		if (findSet(u, parent) != findSet(v, parent)) {
			return prioQ.top().first;
		}
		prioQ.pop();
	}
}

double clustering(vector<int> &x, vector<int> &y, int k) {
	//write your code here
	return mstKruskal(x, y, k);
}

int main() {
	size_t n;
	int k;
	std::cin >> n;
	vector<int> x(n), y(n);
	for (size_t i = 0; i < n; i++) {
		std::cin >> x[i] >> y[i];
	}
	std::cin >> k;
	std::cout << std::setprecision(10) << clustering(x, y, k) << std::endl;
	//system("pause");
}
