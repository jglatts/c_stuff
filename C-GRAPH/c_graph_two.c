#include <stdio.h>
#include <stdlib.h>

struct Node {
	int vertex;
	struct Node* next;
};

struct Graph {
	int num_vertices;
	int* visited;
	struct Node** adj_list;
};

struct Node* create_node(int v) {
	struct Node* new_node = malloc(sizeof(struct Node));
	new_node->vertex = v;
	new_node->next = NULL;
	return new_node;
}

struct Graph* create_graph(int vertices) {
	struct Graph* graph = malloc(sizeof(struct Graph));
	graph->num_vertices = vertices;
	graph->adj_list = malloc(vertices * sizeof(struct Node*));
	graph->visited = malloc(vertices * sizeof(int));
	for (int i = 0; i < vertices; i++) {
		graph->adj_list[i] = NULL;
		graph->visited[i] = 0;
	}
	return graph;
}

void add_edge(struct Graph* graph, int s, int d) {
	struct Node* new_node = create_node(d);
	new_node->next = graph->adj_list[s];
	graph->adj_list[s] = new_node;
	new_node = create_node(s);
	new_node->next = graph->adj_list[d];
	graph->adj_list[d] = new_node;
}

void print_graph(struct Graph* graph) {
	int v;
	for (v = 0; v < graph->num_vertices; v++) {
		struct Node* temp = graph->adj_list[v];
		printf("\n Vertex %d: ", v);
		while (temp) {
			printf("%d -> ", temp->vertex);
			temp = temp->next;
		}
		printf("\n");
	}
}

void dfs(struct Graph* graph, int s) {
	struct Node* src_adj_list = graph->adj_list[s];
	struct Node* temp = src_adj_list;
	graph->visited[s] = 1;
	printf("Visited %d \n", s);
	while (temp != NULL) {
		int connected_vertex = temp->vertex;
		if (graph->visited[connected_vertex] == 0) {
			dfs(graph, connected_vertex);
		}
		temp = temp->next;
	}

}

void has_path(struct Graph* graph, int s, int d) {
	dfs(graph, s);
	if (graph->visited[d] == 1) puts("Path Found");
	else puts("Path Not Found");
}

int main() {
	struct Graph* graph = create_graph(5);
	add_edge(graph, 0, 1);
	add_edge(graph, 0, 2);
	add_edge(graph, 0, 3);
	add_edge(graph, 1, 2);
	add_edge(graph, 1, 4);
	print_graph(graph);
	has_path(graph, 0, 4);
	return 0;
}
