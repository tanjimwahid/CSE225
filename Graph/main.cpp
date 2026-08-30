#include "graphtype.h"
#include "graphtype.cpp"
#include <iostream>
using namespace std;

int main()
{
    GraphType<char> graph(20);

    // Step 1: add every vertex
    char verts[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    for (char v : verts)
        graph.AddVertex(v);

    // Step 2: add every edge from the diagram (all weight 1)
    graph.AddEdge('H', 'F', 1);
    graph.AddEdge('F', 'G', 1);
    graph.AddEdge('G', 'D', 1);
    graph.AddEdge('H', 'E', 1);
    graph.AddEdge('E', 'D', 1);
    graph.AddEdge('D', 'A', 1);
    graph.AddEdge('A', 'B', 1);
    graph.AddEdge('A', 'C', 1);

    cout << "Graph generated" << endl
         << endl;

    // Step 3: ask questions
    cout << "OutDegree(D) = " << graph.OutDegree('D') << endl;

    cout << "FoundEdge(A,D): "
         << (graph.FoundEdge('A', 'D') ? "There is an edge." : "There is no edge.") << endl;
    cout << "FoundEdge(B,D): "
         << (graph.FoundEdge('B', 'D') ? "There is an edge." : "There is no edge.") << endl;

    cout << "\nDFS B->E: ";
    graph.DFS('B', 'E');

    cout << "DFS E->B: ";
    graph.DFS('E', 'B');

    cout << "\nBFS B->E: ";
    graph.BFS('B', 'E');

    cout << "BFS E->B: ";
    graph.BFS('E', 'B');

    cout << "\nShortest Path Length B->E: "
         << graph.ShortestPathLength('B', 'E') << endl;

    return 0;
}