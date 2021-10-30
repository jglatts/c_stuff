#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <queue>
#include <stack>
#include "graph.h"

using namespace std;

Graph::Graph(int v, int e) {
	this->verts = v;
	this->edges = e;
	for (int i = 0; i < verts; ++i) {
		adjList.insert(adjList.begin() + i, { -1 });
	}
}

void Graph::addEgde(int from, int to) {
	adjList.at(from).push_back(to);
	adjList.at(to).push_back(from);
}

void Graph::bfs(int s) {
	queue<int> q;
	vector<bool> marked;
	for (int i = 0; i < verts; ++i) {
		marked.insert(marked.begin() + i, false);
	}
	q.push(s);
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		marked[node] = true;
		cout << "Looking at " << node << " -> ";
		for (int i = 0; i < adjList[node].size(); ++i) {
			if (adjList[node].at(i) >= 0) {
				cout << adjList[node].at(i) << " ";
				if (!marked[adjList[node].at(i)]) {
					q.push(adjList[node].at(i));
					marked[adjList[node].at(i)] = true;
				}
			}
		}
		cout << " " << endl;
	}
}

void Graph::dfs(int s) {
	stack<int> st;
	vector<bool> marked;
	for (int i = 0; i < verts; ++i) {
		marked.insert(marked.begin() + i, false);
	}
	st.push(s);
	while (!st.empty()) {
		int node = st.top();
		st.pop();
		marked[node] = true;
		cout << "Looking at " << node << " -> ";
		for (int i = 0; i < adjList[node].size(); ++i) {
			if (adjList[node].at(i) >= 0) {
				cout << adjList[node].at(i) << " ";
				if (!marked[adjList[node].at(i)]) {
					st.push(adjList[node].at(i));
					marked[adjList[node].at(i)] = true;
				}
			}
		}
		cout << " " << endl;
	}
}

void Graph::printGraph() {
	for (int i = 0; i < verts; ++i) {
		cout << i << " -> ";
		for (int j = 0; j < adjList.at(i).size(); ++j) {
			if (adjList[i].at(j) >= 0 )
				cout << adjList[i].at(j) << " ";
		}
		cout << "" << endl;
	}
}

void Graph::testGraph() {
	this->addEgde(0, 1);
	this->addEgde(4, 3);
	this->addEgde(0, 2);
	this->addEgde(0, 3);
	this->addEgde(2, 3);
	this->addEgde(1, 2);
	this->addEgde(3, 1);
	this->bfs(0);
	cout << "" << endl;
	this->dfs(0);
}

