#include <stdio.h>
#include <stdlib.h>

#define inf 99999

struct Edge{
    int u,v,weight;
};

struct Graph{
    int no_nodes,no_edges;
    struct Edge edges[1000];
};

void bellman_ford(struct Graph *graphs, int start_node, int distances[10]){
    int i,j,u,v,weight;
    for(i=0;i<graphs->no_nodes;i++){
        distances[i]=inf;
    }
    distances[start_node]=0;
    for(i=0;i<graphs->no_nodes;i++){
        for(j=0;j<graphs->no_edges;j++){
            u=graphs->edges[j].u;
            v=graphs->edges[j].v;
            weight=graphs->edges[j].weight;

            if(distances[u]!=inf && distances[v]>weight +distances[u]){
                distances[v]=distances[u]+weight;
            }

        }
    }
    

        for(i=0;i<graphs->no_nodes;i++){
        
            u=graphs->edges[i].u;
            v=graphs->edges[i].v;
            weight=graphs->edges[i].weight;

            if(distances[u]!=inf && distances[v]>weight +distances[u]){
                printf("Negative cycle");
                exit(0);
            }

        
    }
    

}

int main(){
    int i,start_node,distances[1000];
    struct Graph graph;
    printf("No_nodes and edges");
    scanf("%d %d",&graph.no_nodes,&graph.no_edges);
    printf("U,V and weight");
    for(i=0;i<graph.no_edges;i++){
        scanf("%d %d %d",&graph.edges[i].u,&graph.edges[i].v,&graph.edges[i].weight);
    }
    printf("Starting node is:");
    scanf("%d",&start_node);
    bellman_ford(&graph,start_node,distances);
    for(i=0;i<graph.no_nodes;i++){
        printf("Shortest edges from %d->%d is %d\n",start_node,i,distances[i]);
    }
    return 0;
}