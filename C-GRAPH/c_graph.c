#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GRAPH_SIZE 50

/* Graph Nodes */
typedef struct Node {
	int data;
	int edge_count;
	struct Node* edge_to[10];	// max of 10 edges for now
} Node;

struct Node* all_nodes[GRAPH_SIZE];
int _count;

Node* create_new_node(int d) {
	Node* n = (Node*)malloc(sizeof(Node));
	n->data = d;
	n->edge_count = 0;
	return n;
}

int has_edge(Node* src, Node* dest) {
	int i;
	for (i = 0; i < src->edge_count; ++i) {
		// try to do a check with mem. as well
		if (src->edge_to[i]->data == dest->data)
			return 1;
	}
	return 0;
}

void add_new_edge(Node* n, int new_data) {
	n->edge_to[n->edge_count++] = create_new_node(new_data);
}

int graph_contains_node(int d) {
        int i;
        for (i = 0; i < _count; ++i) {
                if (all_nodes[i]->data == d) return 1;

        }
        return 0;
}

Node* get_node_handle(int d) {
        int i;
        for (i = 0; i < _count; ++i) {
                Node* n = all_nodes[i];
                if (n->data == d) return n;

        }
        return NULL;
}

void read_new_graph_file(char *file_name) {
	FILE *fp;
	int err;
	int num_nodes, num_edges;
	int nodes_arr[20];
	printf("Reading file: %s\n", file_name);
	fp = fopen(file_name, "r");
	if (fp != NULL) {
		fscanf(fp, "%d %d", &num_nodes, &num_edges);
		printf("Number of Nodes From File = %d\n", num_nodes);
		printf("Number of Edges From File = %d\n", num_edges);
		while (!feof(fp)) {
			int src, dest;
			fscanf(fp, "%d %d", &src, &dest);
			if (!graph_contains_node(src)) {
				Node* n = create_new_node(src);
				add_new_edge(n, dest);
				all_nodes[_count++] = n;
				//n->edge_count++;
			}
			else {
				Node* n = get_node_handle(src);
				add_new_edge(n, dest);
				//n->edge_count++;
			}
		}
	}
	else printf("Could not open file");
}

void print_edge_info(Node* n) {
	if (n->edge_count > 0) {
		printf("Edges From %d: ", n->data);
		for (int i = 0; i < n->edge_count; ++i) {
			printf("%d ", n->edge_to[i]->data);
		}
		printf("\n");
	}
	else printf("No Edges From %d\n", n->data);
}

void print_all_nodes() {
	int i, x;
	for (i = 0; i < _count; ++i) {
		Node* n = all_nodes[i];
		printf("Edges from %d: ", n->data);
		for (x = 0; x < n->edge_count; ++x) {
			printf("%d ", n->edge_to[x]->data);
		}
		puts("");
	}
}

void dfs(Node *src, int marked[], int x) {
	// only checking immediate neighbors
	int edges[src->edge_count];
	printf("Looking at Node with data %d and Index %d\n", src->data, x);
	marked[x] = 1;
	for (int i = 0; i < src->edge_count; ++i) {
		printf("%d -> %d\n", src->data, src->edge_to[i]->data);
		if (marked[src->edge_to[i]->data] != 1) {
		 	dfs(src->edge_to[i], marked, src->edge_to[i]->data);
		}
	} 
	free(src);
}

void has_path(int source, int dest) {
	Node *src_node = all_nodes[source];
	int marked[GRAPH_SIZE] = {0}; 
	printf("\nNode #%d has %d edges\n", src_node->data, src_node->edge_count);
	dfs(src_node, marked, source);
	marked[dest] == 1 ? puts("Path Found") : puts("No Path Found");	
	puts("");
}

int main(int argc, char *argv[]) {
	char *test = argv[1];
	if (argc < 2) {
		puts("Please supply a input file");
		return 1;
	}
	else if (argc == 4){
		read_new_graph_file(argv[1]);
		print_all_nodes();
		has_path(atoi(argv[2])-1, atoi(argv[3]));
	}
	else {
		read_new_graph_file(argv[1]);
		print_all_nodes();
	}
	return 0;
}

