class Grafo:
    def __init__(self, vertices):
        self.numeroDeVertices = vertices
        self.grafo = [[0 for i in range(vertices)] for j in range(vertices)]

    def addAresta(self, linha, coluna, valor, tipo):
        if tipo == 'aresta':
            self.grafo[linha][coluna] = valor
            self.grafo[coluna][linha] = valor
        elif tipo == 'arco':
            self.grafo[linha][coluna] = valor

    def printGrafo(self):
        print("Grafo: \n")
        for i in range(self.numeroDeVertices):
            for j in range(self.numeroDeVertices):
                if self.grafo[i][j] == 999:
                    print(' ', "INF".rjust(3), end="")
                else:
                    print(' ', f"{str(self.grafo[i][j]): >3}", end="")
            print("\n")

    def greedyColoring(self):
        t_ = colorDict = {}
        degree = []
        for i in range(self.numeroDeVertices):
            t_[i] = i
            degree.append(sum(self.grafo[i]))
            colorDict[i] = ["Cercado 1", "Cercado 2", "Cercado 3", "Cercado 4"]

        sorted_node = []

        for i in range(len(degree)):
            _max = 0
            j = 0
            for j in range(len(degree)):
                if j not in sorted_node:
                    if degree[j] > _max:
                        _max = degree[j]
                        idx = j
            sorted_node.append(idx)

        solution = {}
        for n in sorted_node:
            setTheColor = colorDict[n]
            solution[n] = setTheColor[0]
            adjacentNode = self.grafo[n]
            for j in range(len(adjacentNode)):
                if adjacentNode[j] == 1 and (setTheColor[0] in colorDict[j]):
                    colorDict[j].remove(setTheColor[0])

        for t, w in sorted(solution.items()):
            print("Vértice", t, " = ", w)

        print("Numero de Cercados: ", len(set(list(solution.values()))))


g = Grafo(10)

g.addAresta(0, 2, 1, "aresta")
g.addAresta(1, 3, 1, "aresta")
g.addAresta(2, 3, 1, "aresta")
g.addAresta(4, 5, 1, "aresta")
g.addAresta(4, 9, 1, "aresta")
g.addAresta(5, 6, 1, "aresta")
g.addAresta(6, 7, 1, "aresta")
g.addAresta(6, 9, 1, "aresta")
g.addAresta(7, 8, 1, "aresta")
g.addAresta(8, 9, 1, "aresta")


g.printGrafo()

g.greedyColoring()
