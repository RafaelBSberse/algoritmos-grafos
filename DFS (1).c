#include <stdio.h>
#include <stdbool.h>

#define N 5

int visit[N];
int G[N][N];
int ncc = 0;
bool onlyCount = false;

void DFS(int v){
    int i;
    visit[v] = 1;

    !onlyCount && printf("%d ", v+1);  

    for(i = 0; i < N; i++){
        if(G[v][i] && !visit[i]){
            DFS(i);   
        }
    }
}

void addEdge(char edge[7], int i, int j){
    if(edge == "aresta"){
        G[i][j] = G[j][i] = 1;
    } else if (edge == "arco"){
        G[i][j] = 1;
    }
}

void setMatrix(){
    int i, j;

    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            G[i][j] = 0;
        }
    }
}

void showMatrix(){
    int i, j;

    printf("\n");
    printf(" GRAFO |");
    for(i = 0; i < N; i++){
        printf(" (%d) |", i+1);
    }
    printf("\n");
    printf("--------");
    for(j = 0; j < N; j++){
        printf("------");
    }
    printf("\n");

    for(i = 0; i < N; i++){
        printf("  (%d)  |", i+1);
        for(j = 0; j < N; j++){
            printf("  %d  |", G[i][j]);
        }
        printf("\n");
        printf("--------");
        for(j = 0; j < N; j++){
            printf("------");
        }
        printf("\n");
    }
}

void main(){
    int i;

    setMatrix();
    
    addEdge("aresta", 0, 1);
    addEdge("aresta", 1, 2);
    addEdge("aresta", 2, 0);
    addEdge("aresta", 3, 4);

    showMatrix();

    for(i = 0; i < N; i++) visit[i] = 0;

    printf("\n");
    printf("DFS (Começando do vértice 2): ");
    DFS(1);    
    printf("\n");

    for(i = 0; i < N; i++) visit[i] = 0;
    onlyCount = true;

    for(i = 0; i < N; i++){
        if(!visit[i]){
            ncc++;
            DFS(i);
        }
    }

    printf("Componentes Conexos: %d", ncc); 
    printf("\n");
}   