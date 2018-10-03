// connecting_points.cpp: 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <limits>
#include <queue>
#include <functional>
#include <set>

using namespace std;

double dis(vector<int> &x, vector<int> &y, int v, int z) {
	return sqrt((x[v] - x[z])*(x[v] - x[z]) + (y[v] - y[z])*(y[v] - y[z]));
}

void mstPrim(vector<int> &x, vector<int> &y, vector<double> &cost) {
	//priority_queue<pair<double, int>, vector<pair<double, int> >, greater<pair<double, int> > > prioQ;
	set<pair<double, int>> prioQ;
	vector<bool> inQueue(x.size(), true);
	for (size_t i = 0; i < x.size(); i++) {
		prioQ.insert(make_pair(cost[i], i));
	}
	while (!prioQ.empty()) {
		int v = (*prioQ.begin()).second;
		prioQ.erase(*prioQ.begin());
		inQueue[v] = false;
		for (size_t i = 0; i < x.size(); i++) {
			if (inQueue[i] == true) {
				int z = i;
				double disTemp = dis(x, y, v, z);
				if (cost[z] > disTemp) {
					prioQ.erase(*(prioQ.find(make_pair(cost[z], z))));
					cost[z] = disTemp;
					prioQ.insert(make_pair(disTemp, z));
				}
			}
		}
	}
}

double minimum_distance(vector<int> &x, vector<int> &y) {
	double result = 0.;
	//write your code here
	vector<double> cost(x.size(), numeric_limits<double>::max());
	cost[0] = 0;
	mstPrim(x, y, cost);
	for (size_t i = 0; i < cost.size(); i++) {
		result += cost[i];
	}
	return result;
}

int main() {
	size_t n;
	cin >> n;
	vector<int> x(n), y(n);
	for (size_t i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}
	cout << std::setprecision(10) << minimum_distance(x, y) << endl;
	//system("pause");
}
