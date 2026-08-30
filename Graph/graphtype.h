#ifndef GRAPHTYPE_H
#define GRAPHTYPE_H
#include "stacktype.h"
#include "queuetype.h"
template <class T>
class GraphType
{
private:
    int numVertices;
    int maxVertices;
    T *vertices;
    int **edges;
    bool *marks;

public:
    GraphType();
    GraphType(int maxV);
    ~GraphType();
    void MakeEmpty();
    bool IsEmpty();
    bool IsFull();
    void AddVertex(T vertex);
    void AddEdge(T fromVertex, T toVertex, int weight);
    int WeightIs(T fromVertex, T toVertex);
    void GetToVertices(T vertex, QueueType<T> &adjVertices);
    void ClearMarks();
    void MarkVertex(T vertex);
    bool IsMarked(T vertex);
    void DFS(T startVertex, T endVertex);
    void BFS(T startVertex, T endVertex);
    int OutDegree(T vertex);
    bool FoundEdge(T u, T v);
    int ShortestPathLength(T startVertex, T endVertex);
};
#endif