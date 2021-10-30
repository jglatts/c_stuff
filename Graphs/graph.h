#ifndef GRAPH__H
#define GRAPH__H

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>

class Graph
{
public:
	Graph(int, int);
	void addEgde(int, int);
	void testGraph();
	void printGraph();
	void bfs(int);
	void dfs(int);

private:
	int verts;
	int edges;
	std::vector<std::vector<int>> adjList;
};

#endif // !GRAPH__H
