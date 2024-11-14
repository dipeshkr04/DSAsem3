#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void info() {
    time_t t;
    time(&t);
    printf("DIPESH KUMAR\nBT23CSH043\n\n%s\n", ctime(&t));
    return;
}

struct Node {
    int dest;
    struct Node* next;
};

struct AdjList {
    struct Node* head;
};

struct Graph {
    int num_vertices;
    struct AdjList* array;
};

struct Node* createNewNode(int dest) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->num_vertices = V;
    graph->array = (struct AdjList*)malloc(V * sizeof(struct AdjList));
    for (int i = 0; i < V; ++i)
        graph->array[i].head = NULL;
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNewNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
    newNode = createNewNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

void printGraph(struct Graph* graph) {
    for (int v = 0; v < graph->num_vertices; ++v) {
        struct Node* temp = graph->array[v].head;
        printf("\n Adjacency list of vertex %d\n head ", v);
        while (temp) {
            printf("-> %d", temp->dest);
            temp = temp->next;
        }
        printf("\n");
    }
}

void DepthFirstSearch(int v, struct Graph* graph, int* visited) {
    visited[v] = 1;
    printf("%d ", v);
    struct Node* temp = graph->array[v].head;
    while (temp) {
        if (!visited[temp->dest])
            DepthFirstSearch(temp->dest, graph, visited);
        temp = temp->next;
    }
}

void depthFirstSearch(struct Graph* graph, int start_vertex) {
    int* visited = (int*)calloc(graph->num_vertices, sizeof(int));
    printf("Depth-First Search (DFS) starting from vertex %d: ", start_vertex);
    DepthFirstSearch(start_vertex, graph, visited);
    printf("\n");
    free(visited);
}

void BreadthFirstSearch(struct Graph* graph, int start_vertex) {
    int* visited = (int*)calloc(graph->num_vertices, sizeof(int));
    int queue[graph->num_vertices];
    int front = 0, rear = 0;
    queue[rear++] = start_vertex;
    visited[start_vertex] = 1;
    printf("Breadth-First Search (BFS) starting from vertex %d: ", start_vertex);
    while (front < rear) {
        int v = queue[front++];
        printf("%d ", v);
        struct Node* temp = graph->array[v].head;
        while (temp) {
            if (!visited[temp->dest]) {
                queue[rear++] = temp->dest;
                visited[temp->dest] = 1;
            }
            temp = temp->next;
        }
    }
    printf("\n");
    free(visited);
}

int main() {
    info();
    int V = 5;
    struct Graph* graph = createGraph(V);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    printGraph(graph);
    depthFirstSearch(graph, 0);
    BreadthFirstSearch(graph, 0);
    return 0;
}