// Closeness centrality1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <queue> 
#include <list>
#include <iomanip> 
#include <fstream>
using namespace std;


vector<int> get_shortest_distance(int src, vector< list< pair<int, int> > > graph);

double closeness_centrality_node(int index, vector< list< pair<int, int> > > graph);

vector<double>closeness_centrality_graph(vector< list< pair<int, int> > > graph);

int main()
{
	int n, m;
	ifstream myfile;
	
	myfile.open("input.txt");

	if (myfile.is_open())
	{

	}
	else
	{

		cout<<"error";

	}
	
	myfile >> n >> m;	
	vector< list< pair<int, int> > > graph(n);
	vector<double>out1;
	for (int i = 0; i < m; i++)
	{
		int x, y, z;
		myfile >> x >> y >> z;

		graph[x].push_back(make_pair(y, z));
		graph[y].push_back(make_pair(x, z));

	}

	myfile.close();	
	out1 = closeness_centrality_graph(graph);

	for (int j = 0; j < out1.size(); j++)
	{
		cout << setprecision(11) << out1[j] << '\n';
	}
	
}

/*
a function that implement dijestra algorithm
parameters:
1-the index of the source node that we want to calculate its distance from all other nodes in the graph
2- the given graph
*/

class Comparepairs
{
public:
	bool operator()(pair<int, int> p1, pair<int, int> p2) {
		return p1.second > p2.second;
	}
};

vector<int> get_shortest_distance(int src, vector< list< pair<int, int> > > graph)
{
	list< pair<int, int> >::iterator i;
	priority_queue < pair<int, int>, vector< pair<int, int> >, Comparepairs> heap;
	vector<int> distance_from_nodes(graph.size(), MAX_INT);
	heap.push({ src,0 });


	while (!heap.empty())
	{
		int current_node = heap.top().first;
		int current_distance = heap.top().second;

		heap.pop();

		if (distance_from_nodes[current_node] != MAX_INT)
			continue;

		distance_from_nodes[current_node] = current_distance;

		for (i = graph[current_node].begin(); (i != graph[current_node].end()); i++)
		{
			pair<int, int>p = *i;
			p.second += current_distance;

			if (distance_from_nodes[p.first] != MAX_INT)
				continue;
			heap.push(p);
		}
	}
	return distance_from_nodes;
}


double closeness_centrality_node(int index, vector< list< pair<int, int> > > graph)
{
	vector <int> out;
	out = get_shortest_distance(index, graph);
	int sum = 0, n = graph.size();

	double cc = 0;
	int size = out.size();
	for (int i = 0; i < size; i++)
	{
		sum += out[i];

	}

	cc = ((double)(n - 1)) / ((double)sum);
	return cc;

}


vector<double>closeness_centrality_graph(vector< list< pair<int, int> > > graph)
{
	int n = graph.size();
	vector<double> out(n);
	for (int i = 0; i < n; i++)
	{
		out[i] = closeness_centrality_node(i, graph);

	}

	return out;


}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select 
