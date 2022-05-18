class Grafo:
    def __init__(self, vertices):
        self.numeroDeVertices = vertices
        self.grafo = dist = [[999 for i in range(vertices)] for j in range(vertices)]

    def printGrafo(self):
        print("Grafo: \n")
        for i in range(self.numeroDeVertices):
            for j in range(self.numeroDeVertices):
                if self.grafo[i][j] == 999:
                    print(' ', "INF".rjust(3), end="")
                else:
                    print(' ', f"{str(self.grafo[i][j]): >3}", end="")
            print("\n")

    def addAresta(self, linha, coluna, valor, tipo):
        if tipo == 'aresta':
            self.grafo[linha][coluna] = valor
            self.grafo[coluna][linha] = valor
        elif tipo == 'arco':
            self.grafo[linha][coluna] = valor

    def floyd_warshall(self):
        distancia = self.grafo.copy()

        for k in range(self.numeroDeVertices):
            for i in range(self.numeroDeVertices):
                for j in range(self.numeroDeVertices):
                    distancia[i][j] = min(distancia[i][j], distancia[i][k] + distancia[k][j])
        self.mostraResultado(distancia)

    def mostraResultado(self, distancia):
        print("\nDistancias minimas entre os vértices\n")
        for i in range(self.numeroDeVertices):
            for j in range(self.numeroDeVertices):
                print(" ", end="")
                if (distancia[i][j] == 999):
                    print(" INF".rjust(3), end="")
                else:
                    print(" ", f"{distancia[i][j]}".rjust(2), end="")
            print("\n")

g = Grafo(4)

g.addAresta(0, 0, 0, "arco")
g.addAresta(0, 1, 5, "arco")
g.addAresta(0, 3, 10, "arco")
g.addAresta(1, 1, 0, "arco")
g.addAresta(1, 2, 3, "arco")
g.addAresta(2, 2, 0, "arco")
g.addAresta(2, 3, 1, "arco")
g.addAresta(3, 3, 0, "arco")

g.printGrafo()

g.floyd_warshall()