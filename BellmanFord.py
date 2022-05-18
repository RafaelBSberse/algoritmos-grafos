class Grafo:
    def __init__(self, vertices):
        self.numeroDeVertices = vertices
        self.grafo = dist = [[0 for i in range(vertices)] for j in range(vertices)]

    def printGrafo(self):
        print('\n-------', end='')

        for _ in range(self.numeroDeVertices):
            print('------', end='')

        print("\n|  M", end='  |  ')

        for i in range(self.numeroDeVertices):
            print(i + 1, end='  |  ')

        print('\n-------', end='')

        for _ in range(self.numeroDeVertices):
            print('------', end='')

        for i in range(self.numeroDeVertices):
            print('\n|  ', end='')
            print(i + 1, end="  |")
            for j in range(self.numeroDeVertices):
                print(' ', self.grafo[i][j], end='  |')
            print('\n-------', end='')
            for _ in range(self.numeroDeVertices):
                print('------', end='')

    def addAresta(self, linha, coluna, valor, tipo):
        if tipo == 'aresta':
            self.grafo[linha][coluna] = valor
            self.grafo[coluna][linha] = valor
        elif tipo == 'arco':
            self.grafo[linha][coluna] = valor

    def printArr(self, dist):
        print('\n\n-------------------------------------')
        print("| Vértice | Distância Até a Origem  |")
        for i in range(self.numeroDeVertices):
            print('-------------------------------------')
            print("|    {0}    |            {1}            |".format(i, dist[i]))
        print('-------------------------------------')
    def bellmanFord(self, source):
        dist = [float("Inf")] * self.numeroDeVertices
        dist[source] = 0

        for _ in range(self.numeroDeVertices - 1):
            for i in range(self.numeroDeVertices):
                for j in range(len(self.grafo[i])):
                    if self.grafo[i][j] != 0 and dist[i] != float("Inf") and dist[i] + self.grafo[i][j] < dist[j]:
                        dist[j] = dist[i] + self.grafo[i][j]

        for i in range(self.numeroDeVertices):
            for j in range(len(self.grafo[i])):
                if self.grafo[i][j] and dist[i] != float("Inf") and dist[i] + self.grafo[i][j] < dist[j]:
                    return

        self.printArr(dist)

g = Grafo(5)

g.addAresta(0, 1, -1, "arco")
g.addAresta(0, 2, 4, "arco")
g.addAresta(1, 2, 3, "arco")
g.addAresta(1, 3, 2, "arco")
g.addAresta(1, 4, 2, "arco")
g.addAresta(3, 2, 5, "arco")
g.addAresta(3, 1, 1, "arco")
g.addAresta(4, 3, -3, "arco")

g.printGrafo()

g.bellmanFord(0)