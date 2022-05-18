import java.util.LinkedList;
import java.util.Iterator;

public class BFS {
  private int V;
  private LinkedList<Integer> adj[];

  // Cria o Grafo
  BFS(int v) {
    V = v;
    adj = new LinkedList[v];
    for (int i = 0; i < v; ++i)
      adj[i] = new LinkedList();
  }

  // Adiciona Valores ao Grafo
  void addEdge(int v, int w) {
    adj[v].add(w);
  }

  // Algoritmo BFS
  String BFS(int s) {

    boolean visited[] = new boolean[V];
    String result = "";

    LinkedList<Integer> queue = new LinkedList();

    visited[s] = true;
    queue.add(s);

    while (queue.size() != 0) {
      s = queue.poll();

      Iterator<Integer> i = adj[s].listIterator();
      while (i.hasNext()) {
        int n = i.next();
        if (!visited[n]) {
          visited[n] = true;
          queue.add(n);
        }
      }
      result = result.concat(String.valueOf(s + 1) + " ");
    }

    return result;
  }

  public static void main(String args[]) {
    BFS g = new BFS(4);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    System.out.println("\n GRAFO | (1) | (2) | (3) | (4) |");
    System.out.println("--------------------------------");
    System.out.println("  (1)  |  0  |  1  |  1  |  0  |");
    System.out.println("--------------------------------");
    System.out.println("  (2)  |  0  |  0  |  1  |  0  |");
    System.out.println("--------------------------------");
    System.out.println("  (3)  |  1  |  0  |  0  |  1  |");
    System.out.println("--------------------------------");
    System.out.println("  (4)  |  0  |  0  |  0  |  1  |\n");

    System.out.println(String.format("BFS (Começando no vértice 2): %s", g.BFS(2)));
  }
}