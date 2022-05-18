#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define N 5

bool visit[N];
int G[N][N];
int dist[N];

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
    
    printf("---------");
    for (j = 0; j < N; j++)
    {
        printf("------");
    }
    printf("\n");
    printf("| GRAFO |");
    for (i = 0; i < N; i++)
    {
        printf(" (%d) |", i + 1);
    }
    printf("\n");
    printf("---------");
    for (j = 0; j < N; j++)
    {
        printf("------");
    }
    printf("\n");

    for (i = 0; i < N; i++)
    {
        printf("|  (%d)  |", i + 1);
        for (j = 0; j < N; j++)
        {
            G[i][j] >= 0 && G[i][j] < 10 && printf("  %d  |", G[i][j]);
            G[i][j] >= 10 && G[i][j] < 100 && printf("  %d |", G[i][j]);
            G[i][j] >= 100 && G[i][j] < 1000 && printf(" %d |", G[i][j]);
        }
        printf("\n");
        printf("---------");
        for (j = 0; j < N; j++)
        {
            printf("------");
        }
        printf("\n");
    }
}

void printSolution()
{
    int i;

    printf("---------------------------------\n");
	printf("| Vertice | Distancia da Origem |\n");
    printf("---------------------------------\n");
	for (i = 0; i < N; i++){
		printf("|    %d    |          %d          |\n", i, dist[i]);
        printf("---------------------------------\n");
    }
}

int minDistance(int dist[], bool sptSet[])
{
	int min = INT_MAX, min_index;
    int i;

	for (i = 0; i < N; i++){
		if (sptSet[i] == false && dist[i] <= min){
			min = dist[i], min_index = i;
        }
    }

	return min_index;
}

void dijkstra(int origin)
{
    int i, j, k;

	for(i = 0; i < N; i++){
		dist[i] = INT_MAX, visit[i] = false;
    };

	dist[origin] = 0;

	for(i = 0; i < N - 1; i++) {
		int u = minDistance(dist, visit);

		visit[u] = true;

		for (k = 0; k < N; k++){
			if (!visit[k] && G[u][k] && dist[u] != INT_MAX && dist[u] + G[u][k] < dist[k]){
				dist[k] = dist[u] + G[u][k];
            }
        }

	}

	printSolution();
}

void main()
{
    setMatrix();

    addEdgeWithWeight("aresta", 0, 1, 1);
    addEdgeWithWeight("aresta", 0, 3, 3);
    addEdgeWithWeight("aresta", 0, 4, 10);
    addEdgeWithWeight("aresta", 1, 2, 5);
    addEdgeWithWeight("aresta", 2, 3, 2);
    addEdgeWithWeight("aresta", 2, 4, 1);
    addEdgeWithWeight("aresta", 3, 4, 6);

    printf("\n");
    showMatrix();
    printf("\n");
    printf(" Iniciando Algoritmo de Dijkstra\n");
    dijkstra(0);
    printf("\n");
}