//==============================================================================
// Name        : Graph.h
// Author      : Kyle du Plessis [DPLKYL002]
// Date:       : 07/08/2019
// Description : The K-means clustering algorithm [MacQueen, 1967]
//				 with a Euclidean distance metric - written in C++, Ansi-style
//==============================================================================

#include <vector>
#include <fstream>

#ifndef LIBS_GRAPH_H
#define LIBS_GRAPH_H

using namespace std;

namespace DPLKYL002 {

// static variable
static int CLUSTERID = 3;

class Graph {

private:

	// private members
	int iteration;

	bool converge;

	vector<pair<int, int> > vectPts;

	vector<vector<int> > vectClust;

	vector<pair<float, float>> vectCentr;

	ofstream outputFile;

public:

	// public members
	float computeDistance(pair<int, int> &, pair<float, float> &);

	pair<float, float> generateCentroid(vector<int> &,
			vector<pair<int, int> > &);

	bool checkEqual(pair<float, float>, pair<float, float>);

	void clusterPoints();

	void setPoints(vector<vector<int>>, vector<vector<int>>);

	void iterate();

	void computeMinDistance();

};

}

#endif
