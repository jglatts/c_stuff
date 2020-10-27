#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define GRAPH_SIZE 50

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
                printf("Vertex %d: ", v + 1);
                if (temp->next != NULL) {
                        while (temp) {
                                //printf("Vertex %d: \n", v + 1);
                                if (temp->next != NULL) printf("%d -> ", (temp->vertex) + 1);
                                else printf("%d", (temp->vertex) + 1);
                                temp = temp->next;
                        }
                }
                puts("");

         }
         puts("");
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

bool read_new_graph_file(struct Graph* graph, char *file_name) {
        FILE *fp;
        int err;
        int num_nodes, num_edges;
        printf("\nReading file: %s\n", file_name);
        fp = fopen(file_name, "r");
        if (fp != NULL) {
                fscanf(fp, "%d %d", &num_nodes, &num_edges);
                printf("Number of Nodes From File = %d\n", num_nodes);
                printf("Number of Edges From File = %d\n", num_edges);
                while (!feof(fp)) {
                        int src, dest;
                        fscanf(fp, "%d %d", &src, &dest);
                        add_edge(graph, src-1, dest-1);
                }
                return 1;
         }
         printf("Could not open file");
         return 0;
}

int main() {
        struct Graph* graph = create_graph(GRAPH_SIZE);
        if (read_new_graph_file(graph, "med_graph2.txt")) {
                print_graph(graph);
        }
        return 0;
}
