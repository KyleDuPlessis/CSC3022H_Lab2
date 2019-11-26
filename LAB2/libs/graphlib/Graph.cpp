//==============================================================================
// Name        : Graph.cpp
// Author      : Kyle du Plessis [DPLKYL002]
// Date:       : 07/08/2019
// Description : The K-means clustering algorithm [MacQueen, 1967]
//				 with a Euclidean distance metric - written in C++, Ansi-style
//==============================================================================

#include "Graph.h"

#include <cmath>
#include <iostream>

float DPLKYL002::Graph::computeDistance(pair<int, int> &point1,
		pair<float, float> &point2) {

	float r1 = point1.first - point2.first;

	float r2 = point1.second - point2.second;

	return sqrt(r1 * r1 + r2 * r2);

}

pair<float, float> DPLKYL002::Graph::generateCentroid(vector<int> &vectClust,
		vector<pair<int, int> > &vectPts) {

	pair<float, float> result = pair<float, float>(0, 0);

	for (auto pt = vectClust.begin(); pt != vectClust.end(); ++pt) {

		result.first += vectPts[*pt].first;

		result.second += vectPts[*pt].second;

	}

	result.first = result.first / vectClust.size();

	result.second = result.second / vectClust.size();

	return result;

}

bool DPLKYL002::Graph::checkEqual(pair<float, float> vectCentr,
		pair<float, float> vectPrevCentr) {

	float epsilon = 0.0000001;

	return abs(vectCentr.first - vectPrevCentr.first) < epsilon
			&& abs(vectCentr.second - vectPrevCentr.second) < epsilon;

}

void DPLKYL002::Graph::setPoints(vector<vector<int>> v,
		vector<vector<int>> initialCentr) {

	vector<pair<int, int> > vectTemp;

	for (size_t i = 0; i < v.size(); i++) {

		vectPts.push_back(pair<int, int>(v[i][0], v[i][1]));

	}

	for (size_t i = 0; i < initialCentr.size(); i++) {

		vectTemp.push_back(
				pair<int, int>(initialCentr[i][0], initialCentr[i][1]));

	}

	for (int i = 0; i < CLUSTERID; ++i) {

		vectClust.push_back(vector<int>());

		vectCentr.push_back(pair<float, float>());

	}

	vectCentr[0] = vectTemp[0];

	vectCentr[1] = vectTemp[1];

	vectCentr[2] = vectTemp[2];

}

void DPLKYL002::Graph::iterate() {

	outputFile << "Iteration " << iteration << endl << endl;

	for (int k = 0; k < CLUSTERID; ++k) {

		outputFile << "Cluster " << k + 1 << ": ";

		for (auto pt = vectClust[k].begin(); pt != vectClust[k].end(); ++pt) {

			outputFile << (*pt + 1);

			if (pt != (vectClust[k].end() - 1)) {

				outputFile << ", ";

			}
		}

		outputFile << endl;

		outputFile << "Centroid: (" << vectCentr[k].first << ", "
				<< vectCentr[k].second << ")" << endl << endl;

	}

	outputFile << endl << endl;

}

void DPLKYL002::Graph::computeMinDistance() {

	auto vectPrevCentr = vectCentr;

	for (int k = 0; k < CLUSTERID; ++k) {

		vectClust[k].clear();

	}

	for (unsigned int k = 0; k < vectPts.size(); ++k) {

		auto point1 = vectPts[k];

		float minimumDist = -1;

		int clusterNum = -1;

		for (int n = 0; n < CLUSTERID; ++n) {

			auto point2 = vectCentr[n];

			float distance = computeDistance(point1, point2);

			if (minimumDist == -1 || distance < minimumDist) {

				minimumDist = distance;

				clusterNum = n;

			}

		}

		vectClust[clusterNum].push_back(k);

	}

	for (int k = 0; k < CLUSTERID; ++k) {

		vectCentr[k] = generateCentroid(vectClust[k], vectPts);

		if (!checkEqual(vectCentr[k], vectPrevCentr[k])) {

			converge = true;

		}

	}

}

void DPLKYL002::Graph::clusterPoints() {

	/*In a text file output the results of each iteration (for each cluster, list the
	 examples that fall into each cluster), and the centroids of each cluster*/

	outputFile = ofstream("answers.txt");

	iteration = 0;

	converge = true;

	while (converge) {

		++iteration;

		converge = false;

		computeMinDistance();

		if (converge == true) {

			iterate();

		}

	}

	outputFile.close();

	cout << "answers.txt written successfully" << endl;

}

