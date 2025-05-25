// Garrett, Brunsch
// Lab #8 Graphs S25

#ifndef GRAPH_TYPE_H
#define GRAPH_TYPE_H

#include "QueType.h"
#include <stdexcept>
#include <string>

template<class VertexType>
class GraphType
{
private:
	static const int DEFAULT_SIZE = 50;
	const int NULL_EDGE = 0;
	int numVertices = 0;
	int maxVertices = 1;
	int edges[DEFAULT_SIZE][DEFAULT_SIZE] = {{0}}; // Arbitrarily replaced from hard coded 50/50 value to better conform to class style preferences

	bool* marks = nullptr;	// marks[i] is mark for vertices[i].
	VertexType* vertices = nullptr;

	void clearData();

public:
  void AddVertex(VertexType);
  void AddEdge(VertexType, VertexType, int);
  void DeleteEdge(VertexType fromVertex, VertexType toVertex);
  bool EdgeExists(VertexType fromVertex, VertexType toVertex) const; 

  int WeightIs(VertexType fromVertex, VertexType toVertex) const;
  int IndexIs(VertexType vertex) const;
  
  void setGraph(int size);
  VertexType* GetVertices() const { return vertices; }; 
  void GetToVertices(VertexType, QueType<VertexType>&) const;

  GraphType();                  // Default of 50 vertices
  GraphType(int maxV);          // maxV <= 50
  GraphType(const GraphType<VertexType>& other);
  GraphType<VertexType>& operator=(const GraphType<VertexType>& other);
  ~GraphType();
};

#endif // GRAPH_TYPE_H
