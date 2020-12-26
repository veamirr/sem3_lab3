#include<iostream>
#include "Graph.h"
#include "DirectedGraph.h"

int main()
{
	Graph g(5);
	g.addEdge(0,1,1);
	g.addEdge(0,4,5);
	g.addEdge(1,4,2);
	g.addEdge(1,2,9);
	g.addEdge(4,2,2);
	g.addEdge(3,4,6);
	g.shortest(0);
	//DirectedGraph dg(5);
	//dg.addEdge(0, 1, 1);
	//dg.addEdge(0,3,2);
	//dg.addEdge(1,2,1);
	//dg.addEdge(4,0,1);
	//dg.addEdge(4,3,1);
	//dg.shortest(4);

	return 0;
}
