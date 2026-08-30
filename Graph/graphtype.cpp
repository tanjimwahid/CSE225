#include "graphtype.h"
#include "stacktype.cpp"
#include "queuetype.cpp"
#include <iostream>
using namespace std;
const int NULL_EDGE = 0;
template <class T>
GraphType<T>::GraphType()
{
    numVertices = 0;
    maxVertices = 50;
    vertices = new T[maxVertices];
    marks = new bool[maxVertices];
    edges = new int *[maxVertices];
    for (int i = 0; i < maxVertices; i++)
        edges[i] = new int[maxVertices];
}
template <class T>
GraphType<T>::GraphType(int maxV)
{
    numVertices = 0;
    maxVertices = maxV;
    vertices = new T[maxVertices];
    marks = new bool[maxVertices];
    edges = new int *[maxVertices];
    for (int i = 0; i < maxVertices; i++)
    {
        edges[i] = new int[maxVertices];
        for (int j = 0; j < maxVertices; j++)
            edges[i][j] = 0; // VERY IMPORTANT
    }
    for (int i = 0; i < maxVertices; i++)
        marks[i] = false;
}
template <class T>
GraphType<T>::~GraphType()
{
    delete[] vertices;
    delete[] marks;
    for (int i = 0; i < maxVertices; i++)
        delete[] edges[i];
    delete[] edges;
}
template <class T>
void GraphType<T>::MakeEmpty()
{
    numVertices = 0;
}
template <class T>
bool GraphType<T>::IsEmpty()
{
    return (numVertices == 0);
}
template <class T>
bool GraphType<T>::IsFull()
{
    return (numVertices == maxVertices);
}
// Helper function
template <class T>
int IndexIs(T *vertices, T vertex)
{
    int index = 0;
    while (!(vertex == vertices[index]))
        index++;
    return index;
}
template <class T>
void GraphType<T>::AddVertex(T vertex)
{
    vertices[numVertices] = vertex;
    for (int i = 0; i < numVertices; i++)
    {
        edges[i][numVertices] = NULL_EDGE;
        edges[numVertices][i] = NULL_EDGE;
    }
    numVertices++;
}
template <class T>
void GraphType<T>::AddEdge(T fromVertex, T toVertex, int weight)
{
    int row = IndexIs(vertices, fromVertex);
    int col = IndexIs(vertices, toVertex);
    edges[row][col] = weight;
}
template <class T>
int GraphType<T>::WeightIs(T fromVertex, T toVertex)
{
    int row = IndexIs(vertices, fromVertex);
    int col = IndexIs(vertices, toVertex);
    return edges[row][col];
}
template <class T>
void GraphType<T>::GetToVertices(T vertex, QueueType<T> &adjVertices)
{
    int row = IndexIs(vertices, vertex);
    for (int col = 0; col < numVertices; col++)
        if (edges[row][col] != NULL_EDGE)
            adjVertices.Enqueue(vertices[col]);
}
template <class T>
void GraphType<T>::ClearMarks()
{
    for (int i = 0; i < maxVertices; i++)
        marks[i] = false;
}
template <class T>
void GraphType<T>::MarkVertex(T vertex)
{
    int index = IndexIs(vertices, vertex);
    marks[index] = true;
}
template <class T>
bool GraphType<T>::IsMarked(T vertex)
{
    int index = IndexIs(vertices, vertex);
    return marks[index];
}
template <class T>
void GraphType<T>::DFS(T startVertex, T endVertex)
{
    StackType<T> stack;
    QueueType<T> adj;
    bool found = false;
    ClearMarks();
    stack.Push(startVertex);
    T vertex, item;
    while (!stack.IsEmpty() && !found)
    {
        vertex = stack.Top();
        stack.Pop();
        if (vertex == endVertex)
        {
            cout << vertex << " ";
            found = true;
        }
        else if (!IsMarked(vertex))
        {
            MarkVertex(vertex);
            cout << vertex << " ";
            GetToVertices(vertex, adj);
            while (!adj.IsEmpty())
            {
                adj.Dequeue(item);
                if (!IsMarked(item))
                    stack.Push(item);
            }
        }
    }
    cout << endl;
    if (!found)
        cout << "Path not found." << endl;
}
template <class T>
void GraphType<T>::BFS(T startVertex, T endVertex)
{
    QueueType<T> queue;
    QueueType<T> adj;
    ClearMarks();
    queue.Enqueue(startVertex);
    bool found = false;
    T vertex, item;
    while (!queue.IsEmpty() && !found)
    {
        queue.Dequeue(vertex);
        if (vertex == endVertex)
        {
            cout << vertex << " ";
            found = true;
        }
        else if (!IsMarked(vertex))
        {
            MarkVertex(vertex);
            cout << vertex << " ";
            GetToVertices(vertex, adj);
            while (!adj.IsEmpty())
            {
                adj.Dequeue(item);
                if (!IsMarked(item))
                    queue.Enqueue(item);
            }
        }
    }
    cout << endl;
    if (!found)
        cout << "Path not found." << endl;
}
template <class T>
int GraphType<T>::OutDegree(T vertex)
{
    int row = IndexIs(vertices, vertex);
    int count = 0;
    for (int col = 0; col < numVertices; col++)
        if (edges[row][col] != NULL_EDGE)
            count++;
    return count;
}
template <class T>
bool GraphType<T>::FoundEdge(T u, T v)
{
    return (WeightIs(u, v) != NULL_EDGE);
}
template <class T>
int GraphType<T>::ShortestPathLength(T startVertex, T endVertex)
{
    ClearMarks();
    int distance[50];
    for (int i = 0; i < 50; i++)
        distance[i] = -1;
    QueueType<T> q;
    q.Enqueue(startVertex);
    int startIndex = IndexIs(vertices, startVertex);
    distance[startIndex] = 0;
    while (!q.IsEmpty())
    {
        T v;
        q.Dequeue(v);
        int vIndex = IndexIs(vertices, v);
        QueueType<T> adj;
        GetToVertices(v, adj);
        while (!adj.IsEmpty())
        {
            T w;
            adj.Dequeue(w);
            int wIndex = IndexIs(vertices, w);
            if (distance[wIndex] == -1)
            {
                distance[wIndex] = distance[vIndex] + 1;
                if (w == endVertex)
                    return distance[wIndex];
                q.Enqueue(w);
            }
        }
    }
    return -1; // no path
}