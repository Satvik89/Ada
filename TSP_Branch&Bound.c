#include <stdio.h>
#include <limits.h>

#define MAX_SIZE 10

int n; // Number of cities
int cost[MAX_SIZE][MAX_SIZE]; // Cost matrix
int visited[MAX_SIZE]; // Visited cities
int bestPath[MAX_SIZE]; // Best path so far
int bestCost = INT_MAX; // Best cost so far

void getInput() {
    printf("Enter the number of cities: ");
    scanf("%d", &n);
    
    printf("Enter the cost matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }
}

void printSolution() {
    printf("Best Path: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", bestPath[i] + 1);
    }
    printf("%d\n", bestPath[0] + 1);
    printf("Best Cost: %d\n", bestCost);
}

void branchAndBound(int currentPath[], int level, int currentCost) {
    if (level == n) {
        // Reached the leaf node (all cities visited)
        if (cost[currentPath[level - 1]][currentPath[0]] != 0 && currentCost + cost[currentPath[level - 1]][currentPath[0]] < bestCost) {
            // Update best path and cost
            for (int i = 0; i < n; i++) {
                bestPath[i] = currentPath[i];
            }
            bestCost = currentCost + cost[currentPath[level - 1]][currentPath[0]];
        }
        return;
    }
    
    for (int i = 0; i < n; i++) {
        if (!visited[i] && cost[currentPath[level - 1]][i] != 0) {
            visited[i] = 1;
            currentPath[level] = i;
            
            // Calculate the lower bound
            int lowerBound = currentCost + cost[currentPath[level - 1]][i];
            for (int j = 0; j < n; j++) {
                if (!visited[j] && cost[i][j] != 0 && (lowerBound + cost[i][j]) < bestCost) {
                    lowerBound += cost[i][j];
                }
            }
            
            if (lowerBound < bestCost) {
                branchAndBound(currentPath, level + 1, currentCost + cost[currentPath[level - 1]][i]);
            }
            
            visited[i] = 0;
        }
    }
}

int main() {
    getInput();
    
    int currentPath[MAX_SIZE];
    currentPath[0] = 0;
    visited[0] = 1;
    
    branchAndBound(currentPath, 1, 0);
    
    printSolution();
    
    return 0;
}
