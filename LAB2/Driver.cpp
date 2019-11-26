//==============================================================================
// Name        : Driver.cpp
// Author      : Kyle du Plessis [DPLKYL002]
// Date:       : 07/08/2019
// Description : The K-means clustering algorithm [MacQueen, 1967]
//				 with a Euclidean distance metric - written in C++, Ansi-style
//==============================================================================

#include "Graph.h"

// main function
int main(int argc, char * argv[]) { // argc and argv values passed into main

	DPLKYL002::Graph graph;

	// setting:
	// - the data points of the 8 examples (table 1)
	// - the initial seeds (initial centroid of each cluster) as examples 1, 4 and 7
	graph.setPoints( { { 2, 10 }, { 2, 5 }, { 8, 4 }, { 5, 8 }, { 7, 5 },
			{ 6, 4 }, { 1, 2 }, { 4, 9 } }, { { 2, 10 }, { 5, 8 }, { 1, 2 } });

	// use the implemented K-means algorithm to cluster the 8 examples (table 1) into 3 clusters
	graph.clusterPoints();

	return 0;

}
