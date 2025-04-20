// Garrett, Brunsch
// Lab #8 Graphs S25
// CS_136_14728SP25P
// Due 4/13/25 with extension due 4/20

#include "stdafx.h"
#include "../GraphType.h"
#include "../StackType.h"
#include "../GraphType.cpp"
#include <iostream>

using namespace std;

void displayGraphInfo(const GraphType<char>& graph, const string& label);
void testEdgeExists(GraphType<char>& graph);
void testWeightIs(GraphType<char>& graph);
void testDeleteEdge(GraphType<char>& graph);
void testCopyConstructor();
void testAssignmentOperator();
void runAllTests();

int main() 
{
    cout << "\n\nNow starting automated testing...\n";

    try
    {
        runAllTests();
    }

    catch (const std::runtime_error& e)
    {
        cerr << "Error: " << e.what() << "\n";
    }
    catch (const std::exception& e)
    {
        cerr << "Standard Error: " << e.what() << "\n";
    }
    catch (...)
    {
        cerr << "Unknown error occurred\n";
    }

    cout << "\nAll tests completed. Now exiting program...\n";

    return 0;
}


void runAllTests() 
{

    GraphType<char> graph(10);

    cout << "Adding vertices A, B, C to graph\n";
    graph.AddVertex('A');
    graph.AddVertex('B');
    graph.AddVertex('C');

    cout << "Adding edges: A->B (5), B->C (10)\n";
    graph.AddEdge('A', 'B', 5);
    graph.AddEdge('B', 'C', 10);

    displayGraphInfo(graph, "Initial Graph");

    testEdgeExists(graph);
    testWeightIs(graph);
    testDeleteEdge(graph);
    testCopyConstructor();
    testAssignmentOperator();
}

void displayGraphInfo(const GraphType<char>& graph, const string& label) 
{
    cout << "\n--- " << label << " ---\n"
        "Edge A->B exists: " << (graph.EdgeExists('A', 'B') ? "Yes" : "No")
        << " (Weight: " << graph.WeightIs('A', 'B') << ")\n"

        << "Edge B->C exists: " << (graph.EdgeExists('B', 'C') ? "Yes" : "No")
        << " (Weight: " << graph.WeightIs('B', 'C') << ")\n";
}

void testEdgeExists(GraphType<char>& graph) 
{
    cout << "\n\n=== TEST: EdgeExists() ===\n"
        "Edge A->B exists: " << (graph.EdgeExists('A', 'B') ? "Yes" : "No") << "\n"
        "Fake edge B->A exists: " << (graph.EdgeExists('B', 'A') ? "Yes" : "No") << "\n"
        "Fake edge A->C exists: " << (graph.EdgeExists('A', 'C') ? "Yes" : "No") << "\n";
}

void testWeightIs(GraphType<char>& graph) 
{
    cout << "\n\n=== TEST: WeightIs() ===\n"
        "Weight of edge A->B: " << graph.WeightIs('A', 'B') << "\n"
        "Weight of edge B->C: " << graph.WeightIs('B', 'C') << "\n"
        "Weight of fake edge A->C: " << graph.WeightIs('A', 'C') << "\n";
}

void testDeleteEdge(GraphType<char>& graph)
{
    cout << "\n\n=== TEST: DeleteEdge() ===\n"
        "Before deletion - A->B exists: " << (graph.EdgeExists('A', 'B') ? "Yes" : "No")
        << " (Weight: " << graph.WeightIs('A', 'B') << ")\n";

    cout << "Deleting edge A->B...\n";
    graph.DeleteEdge('A', 'B');

    cout << "After deletion - A->B exists: " << (graph.EdgeExists('A', 'B') ? "Yes" : "No")
        << " (Weight: " << graph.WeightIs('A', 'B') << ")\n";
}

void testCopyConstructor() 
{
    cout << "\n\n=== TEST: Copy Constructor ===\n";

    GraphType<char> graph(10);
    graph.AddVertex('A');
    graph.AddVertex('B');
    graph.AddVertex('C');
    graph.AddEdge('A', 'B', 5);
    graph.AddEdge('B', 'C', 10);

    GraphType<char> graphCopy(graph);
    cout << "Copy created\n";

    displayGraphInfo(graphCopy, "Copied Graph");

    // Modify original to display that a successful copy exists
    cout << "\nDeleting original edge B->C...\n";
    graph.DeleteEdge('B', 'C');

    displayGraphInfo(graph, "Modified Original Graph");
    displayGraphInfo(graphCopy, "Copy Graph (should remain unchanged)");
}

void testAssignmentOperator() 
{
    cout << "\n\n=== TEST: Assignment Operator ===\n";

    GraphType<char> graph(10);
    graph.AddVertex('A');
    graph.AddVertex('B');
    graph.AddVertex('C');
    graph.AddEdge('A', 'B', 5);
    graph.AddEdge('B', 'C', 10);

    GraphType<char> graphAssigned(10);
    graphAssigned.AddVertex('X');
    graphAssigned.AddVertex('Y');
    graphAssigned.AddEdge('X', 'Y', 25);

    cout << "New graph for assignment testing:\n"
        "Edge X->Y exists: " << (graphAssigned.EdgeExists('X', 'Y') ? "Yes" : "No")
        << " (Weight: " << graphAssigned.WeightIs('X', 'Y') << ")\n";

    cout << "\nAssigning original graph to new graph...\n";
    graphAssigned = graph;

    displayGraphInfo(graph, "Original Graph");
    displayGraphInfo(graphAssigned, "Modified assigned graph");

    // Modify original to display that a successful copy exists
    cout << "\nDeleting original edge A->B)...\n";
    graph.DeleteEdge('A', 'B');

    displayGraphInfo(graph, "Modified Original Graph");
    displayGraphInfo(graphAssigned, "Assigned Graph (should remain unchanged)");

    cout << "Now trying to access deleted X-Y:\n";
    cout << "Edge X->Y exists: " << (graphAssigned.EdgeExists('X', 'Y') ? "Yes" : "No"); //Needs separate cout because it is designed to throw an exception
}

/*


Now starting automated testing...
Adding vertices A, B, C to graph
Adding edges: A->B (5), B->C (10)

--- Initial Graph ---
Edge A->B exists: Yes (Weight: 5)
Edge B->C exists: Yes (Weight: 10)


=== TEST: EdgeExists() ===
Edge A->B exists: Yes
Fake edge B->A exists: No
Fake edge A->C exists: No


=== TEST: WeightIs() ===
Weight of edge A->B: 5
Weight of edge B->C: 10
Weight of fake edge A->C: 0


=== TEST: DeleteEdge() ===
Before deletion - A->B exists: Yes (Weight: 5)
Deleting edge A->B...
After deletion - A->B exists: No (Weight: 0)


=== TEST: Copy Constructor ===
Copy created

--- Copied Graph ---
Edge A->B exists: Yes (Weight: 5)
Edge B->C exists: Yes (Weight: 10)

Deleting original edge B->C...

--- Modified Original Graph ---
Edge A->B exists: Yes (Weight: 5)
Edge B->C exists: No (Weight: 0)

--- Copy Graph (should remain unchanged) ---
Edge A->B exists: Yes (Weight: 5)
Edge B->C exists: Yes (Weight: 10)


=== TEST: Assignment Operator ===
New graph for assignment testing:
Edge X->Y exists: Yes (Weight: 25)

Assigning original graph to new graph...

--- Original Graph ---
Edge A->B exists: Yes (Weight: 5)
Edge B->C exists: Yes (Weight: 10)

--- Modified assigned graph ---
Edge A->B exists: Yes (Weight: 5)
Edge B->C exists: Yes (Weight: 10)

Deleting original edge A->B)...

--- Modified Original Graph ---
Edge A->B exists: No (Weight: 0)
Edge B->C exists: Yes (Weight: 10)

--- Assigned Graph (should remain unchanged) ---
Edge A->B exists: Yes (Weight: 5)
Edge B->C exists: Yes (Weight: 10)
Now trying to access deleted X-Y:
Error: Vertex not found in graph

All tests completed. Now exiting program...
*/