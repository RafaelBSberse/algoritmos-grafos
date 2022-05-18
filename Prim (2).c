#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define N 5

bool visit[N];
int G[N][N];

int minWeight(int key[])
{
    int v;
    int min = INT_MAX, min_index;

    for (v = 0; v < N; v++)
        if (visit[v] == false && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

int printPrim(int parent[])
{
    int i;
    int total = 0;

    printf("--------------------\n");
    printf("| Aresta | Tamanho |\n");
    printf("--------------------\n");

    for (i = 1; i < N; i++){
        printf("| %d -- %d |    %d    |\n", parent[i] + 1, i + 1, G[i][parent[i]]);
        printf("--------------------\n");

        total += G[i][parent[i]];
    }

    printf("Distancia Minima Percorrida: %d", total);
}

void prim()
{
    int parent[N];
    int key[N];
    int i, count, v;

    for (i = 0; i < N; i++)
    {
        key[i] = INT_MAX, visit[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (count = 0; count < N - 1; count++)
    {
        int u = minWeight(key);

        visit[u] = true;

        for (v = 0; v < N; v++){
            if (G[u][v] && visit[v] == false && G[u][v] < key[v]){
                parent[v] = u;
                key[v] = G[u][v];
            }
        }
    }

    printPrim(parent);
}

void addEdgeWithWeight(char edge[7], int i, int j, int k)
{
    if (edge == "aresta")
    {
        G[i][j] = G[j][i] = k;
    }
    else if (edge == "arco")
    {
        G[i][j] = k;
    }
}

void setMatrix()
{
    int i, j;

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            G[i][j] = 0;
        }
    }
}

void showMatrix()
{
    int i, j;

    printf("\n");
    printf(" GRAFO |");
    for (i = 0; i < N; i++)
    {
        printf(" (%d) |", i + 1);
    }
    printf("\n");
    printf("--------");
    for (j = 0; j < N; j++)
    {
        printf("------");
    }
    printf("\n");

    for (i = 0; i < N; i++)
    {
        printf("  (%d)  |", i + 1);
        for (j = 0; j < N; j++)
        {
            printf("  %d  |", G[i][j]);
        }
        printf("\n");
        printf("--------");
        for (j = 0; j < N; j++)
        {
            printf("------");
        }
        printf("\n");
    }
}

void main()
{
    setMatrix();

    addEdgeWithWeight("aresta", 0, 1, 2);
    addEdgeWithWeight("aresta", 0, 3, 6);
    addEdgeWithWeight("aresta", 1, 2, 3);
    addEdgeWithWeight("aresta", 1, 3, 8);
    addEdgeWithWeight("aresta", 1, 4, 5);
    addEdgeWithWeight("aresta", 2, 4, 7);
    addEdgeWithWeight("aresta", 3, 4, 9);

    showMatrix();

    printf("\n");

    printf("Arvore Geradora Minima\nIniciando do Vertice 1: \n");
    prim();
}
