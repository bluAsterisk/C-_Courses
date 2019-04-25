#include<iostream>
#include<vector>
#include <string>
using namespace std;
const int INF = 99999999;

void Prim(int matrix[12][12], string vertices[12])
{
	int myMstCost = 0;
	string MSTpath;
	vector<int> visited;
	vector<int> unvisited;
	for (unsigned v = 0; v < 12; v++)
	{
		unvisited.push_back(v);
	}
	visited.push_back(unvisited[0]);
	unvisited.erase(unvisited.begin());
	string source; string dest;
	while (!unvisited.empty())
	{
		int smallest = INF; int index = 0;
		for (unsigned o = 0; o < visited.size(); o++)
		{
			for (unsigned d = 0; d < unvisited.size(); d++)
			{
				if (smallest > matrix[visited[o]][unvisited[d]])
				{
					smallest = matrix[visited[o]][unvisited[d]];
					source = vertices[visited[o]];
					dest = vertices[unvisited[d]];
					index = d;
				}
			}
		}
		myMstCost += smallest;
		MSTpath = MSTpath + source + " to " + dest + ". ";
		visited.push_back(unvisited[index]);
		unvisited.erase(unvisited.begin() + index);
	}
	cout << "Path = " << MSTpath << endl;
	cout << "Cost = " << myMstCost << endl;
}

void Dijkstra(int matrix[12][12], string vertices[12])
{
	string path[12];
	int weight[12];
	vector<int> vertexPool;
	// Step 1: Initialization
	for (unsigned v = 0; v < 12; v++)
	{
		weight[v] = matrix[0][v];
		path[v] = vertices[0] + " to " + vertices[v];
		vertexPool.push_back(v);
	}
	vertexPool.erase(vertexPool.begin()); // We erase the first item, since it represents Seattle, our origin.
	// Step 2: While our pool of unvisited vertexes has values, visit the shortest path, check for new paths, update weight/path if something better found.
	while (!vertexPool.empty())
	{
		int smallest = INF; int index = 0;
		for (unsigned v = 0; v < vertexPool.size(); v++) {
			if (smallest > weight[vertexPool[v]])
			{
				smallest = weight[vertexPool[v]];
				index = v;
			}
		}
		// cout << "Smallest = " << smallest << " @ " << vertices[vertexPool[index]] << ".\n";
		for (unsigned u = 1; u < 12; u++)
		{
			if (weight[u] >(weight[vertexPool[index]] + matrix[vertexPool[index]][u]))
			{
				weight[u] = weight[vertexPool[index]] + matrix[vertexPool[index]][u];
				path[u] = path[vertexPool[index]] + ", " + vertices[vertexPool[index]] + " to " + vertices[u];
			}
		}
		vertexPool.erase(vertexPool.begin() + index); // move on
	}
	// Step 3: Report our results..
	for (unsigned i = 1; i < 12; i++)
	{
		cout << i << " : " << vertices[i] << " = " << weight[i] << " via " << path[i] << ".\n";
	}
}

int main()
{
	string cities[12];
	cities[0] = "Seatle";
	cities[1] = "San Francisco";
	cities[2] = "Denver";
	cities[3] = "Chicago";
	cities[4]= "Los angeles";
	cities[5] = "Kansas City";
	cities[6] = "Dallas";
	cities[7] = "Houston";
	cities[8] = "Atlanta";
	cities[9] = "Miami";
	cities[10] = "New York";
	cities[11] = "Boston";

	int matrix[12][12] =
	{
		{ 0, 807, 1331, 2097, INF, INF, INF, INF, INF, INF, INF, INF }, 	// 0 Seattle
		{ 807, 0, 1267, INF, 381, INF, INF, INF, INF, INF, INF, INF }, 	// 1 San Francisco
		{ 1331, 1267, 0, 1003, 1015, 599, INF, INF, INF, INF, INF, INF },  	// 2 Denver
		{ 2097, INF, 1003, 0, INF, 533, INF, INF, INF, INF, 787, 983 },	// 3 Chicago
		{ INF, 381, 1015, INF, 0, 1633, 1435, INF, INF, INF, INF, INF },	// 4 Los Angeles
		{ INF, INF, 599, 533, 1663, 0, 496, INF, 864, INF, 1260, INF },	// 5 Kansas City
		{ INF, INF, INF, INF, 1435, 496, 0, 239, 781, INF, INF, INF },	// 6 Dallas
		{ INF, INF, INF, INF, INF, INF, 239, 0, 810, 1187, INF, INF }, 	// 7 Houston
		{ INF, INF, INF, INF, INF, 864, 781, 810, 0, 661, 888, INF },	// 8 Atlanta
		{ INF, INF, INF, INF, INF, INF, INF, 1187, 661, 0, INF, INF },	// 9 Miami
		{ INF, INF, INF, 787, INF, 1260, INF, INF, 888, INF, 0, 214 },	// 10 New York
		{ INF, INF, INF, 983, INF, INF, INF, INF, INF, INF, 214, 0 }		// 11 Boston
	};
	cout << "## Calling Dijkstra's Algorithm for Shortest Path from Seattle to Any Destination:\n";
	Dijkstra(matrix, cities);
	cout << "\n\n\n##Calling Prim's Algorithm for MST:\n";
	Prim(matrix, cities);
	//system("PAUSE");
	return 0;
}
