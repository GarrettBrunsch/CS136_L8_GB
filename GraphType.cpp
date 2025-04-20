// Garrett, Brunsch
// Lab #8 Graphs S25

#include "GraphType.h"
#include <utility>

// New functions included below

template<class VertexType>
bool GraphType<VertexType>::EdgeExists(VertexType fromVertex, VertexType toVertex) const
{
    return (edges[IndexIs(fromVertex)][IndexIs(toVertex)] != NULL_EDGE);
}

template<class VertexType>
void GraphType<VertexType>::DeleteEdge(VertexType fromVertex, VertexType toVertex)
{
    edges[IndexIs(fromVertex)][IndexIs(toVertex)] = NULL_EDGE; 
}

template<class VertexType>
int GraphType<VertexType>::WeightIs(VertexType fromVertex, VertexType toVertex) const
{
    return edges[IndexIs(fromVertex)][IndexIs(toVertex)];
}

template<class VertexType>
void GraphType<VertexType>::clearData()
{
    if (vertices != nullptr)
    {
        delete[]vertices;
        vertices = nullptr;
    }

    if (marks != nullptr)
    {
        delete[]marks;
        marks = nullptr;
    }

    numVertices = 0;
}

template<class VertexType>
GraphType<VertexType>::GraphType(const GraphType<VertexType>& other)
{
    try
    {
        numVertices = other.numVertices;
        maxVertices = other.maxVertices;

        vertices = new VertexType[maxVertices];
        marks = new bool[maxVertices];

        for (int i = 0; i < numVertices; i++)
        {
            vertices[i] = other.vertices[i];
            marks[i] = other.marks[i];
        }

        for (int i = 0; i < maxVertices; i++)
        {
            for (int j = 0; j < maxVertices; j++)
            {
                edges[i][j] = other.edges[i][j];
            }
        }
    }
    catch (...)
    {
        clearData();
        throw;
    }

}

template<class VertexType>
GraphType<VertexType>& GraphType<VertexType>::operator=(const GraphType<VertexType>& other)
{
    if (this != &other)
    {
        GraphType<VertexType> temp(other);

        swap(numVertices, temp.numVertices); 
        swap(maxVertices, temp.maxVertices); 
        swap(vertices, temp.vertices); 
        swap(marks, temp.marks); 
        swap(edges, temp.edges); 
    }
	return *this;
}

template<class VertexType>
GraphType<VertexType>::~GraphType()
{
    clearData();
}

// Original file included below

template<class VertexType>
GraphType<VertexType>::GraphType()
{
  numVertices = 0;
  maxVertices = DEFAULT_SIZE;
  vertices = new VertexType[DEFAULT_SIZE];
  marks = new bool[DEFAULT_SIZE];
}

template<class VertexType>
GraphType<VertexType>::GraphType(int maxV)
{
  numVertices = 0;
  maxVertices = maxV;
  vertices = new VertexType[maxV];
  marks = new bool[maxV];
}

template<class VertexType>
void GraphType<VertexType>::AddVertex(VertexType vertex)
{
    if (numVertices >= maxVertices)
    {
        throw std::runtime_error("Cannot add vertex. Graph is full");
    }

  vertices[numVertices] = vertex;

  for (int index = 0; index < numVertices; index++)
  {
    edges[numVertices][index] = NULL_EDGE;
    edges[index][numVertices] = NULL_EDGE;
  }
  numVertices++;
}

template<class VertexType>
int GraphType<VertexType>::IndexIs(VertexType vertex) const
{
  int index = 0;

  while (index < numVertices && !(vertex == vertices[index]))
  {
      index++;
  }

  if (index >= numVertices)
  {
      throw std::runtime_error("Vertex not found in graph");
  }
  return index;
}       

template<class VertexType>
void GraphType<VertexType>::AddEdge(VertexType fromVertex,
     VertexType toVertex, int weight)
{
    if (weight < 0)
    {
        throw std::runtime_error("Edge weight cannot be negative");
    }

    int row = IndexIs(fromVertex);
    int col = IndexIs(toVertex);

   edges[row][col] = weight;
}


template<class VertexType>
void GraphType<VertexType>::GetToVertices(VertexType vertex, 
     QueType<VertexType>& adjVertices) const
{
  int fromIndex = IndexIs(vertex);
  int toIndex = 0;

  for (toIndex = 0; toIndex < numVertices; toIndex++)
  {
      if (edges[fromIndex][toIndex] != NULL_EDGE)
      {
          adjVertices.Enqueue(vertices[toIndex]);
      }
  }
}     



