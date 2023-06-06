#include <stdio.h>

#define MAX 10

int path[MAX];
int graph[MAX][MAX];
int numVertices;

void printHamiltonianCircuit(int numVertices) {
    printf("Hamiltonian Circuit: ");
    for (int i = 0; i < numVertices; i++) {
        printf("%d ", path[i]);
    }
    printf("%d\n", path[0]);  // Complete the circuit by printing the starting vertex again
}

int isValid(int v, int pos) {
    if (graph[path[pos - 1]][v] == 0) {
        return 0;  // If there is no edge between the last added vertex and v, it is not a valid path
    }

    for (int i = 0; i < pos; i++) {
        if (path[i] == v) {
            return 0;  // If v is already in the path, it is not a valid path
        }
    }

    return 1;
}

int cyclefound(int pos) {
    if (pos == numVertices) {
        if (graph[path[pos - 1]][path[0]] == 1) {
            // If there is an edge between the last added vertex and the starting vertex,
            // a Hamiltonian circuit is found
            printHamiltonianCircuit(numVertices);
            return 1;
        } else {
            return 0;
        }
    }

    for (int v = 1; v < numVertices; v++) {
        if (isValid(v, pos)) {
            path[pos] = v;
            if (cyclefound(pos + 1) == 1) {
                return 1;  // If a Hamiltonian circuit is found, return 1
            }
            path[pos] = -1;  // Backtrack and remove the vertex from the path
        }
    }

    return 0;
}

void findHamiltonianCircuit(int startVertex, int numVertices) {
    for (int i = 0; i < numVertices; i++) {
        path[i] = -1;  // Initialize the path array with -1
    }

    path[0] = startVertex;  // Start the path with the given start vertex

    if (cyclefound(1) == 0) {
        printf("No Hamiltonian Circuit found.\n");
    }
}

int main() {
    int i, j;

    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < numVertices; i++) {
        for (j = 0; j < numVertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int startVertex;
    printf("Enter the starting vertex: ");
    scanf("%d", &startVertex);

    findHamiltonianCircuit(startVertex, numVertices);

    return 0;
}
