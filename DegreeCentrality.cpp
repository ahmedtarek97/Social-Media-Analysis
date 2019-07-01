 #include <iostream>
#include <vector>
#include <list>
//#include <algorithms>
#include <utility> 
using namespace std;
int main()
{
	int nodes_num, edge_num ;
	cin >> nodes_num ;
	cin	>> edge_num ;

	vector < list < pair <int, int> > >  adj_list(nodes_num);
	vector <int> score (nodes_num);

	/* this code and its variables is just for filling the adj list*/
	int temp_node ; 
	int temp ;
	pair <int, int > p;
	for (int i = 0; i < edge_num; i++)
	{
		cin >> temp_node;
		cin >> p.first; 
		cin >> p.second;
		adj_list[temp_node].push_back(p);
		temp = p.first;
		p.first = temp_node ;
		adj_list[temp].push_back(p);
	}
		 
	/************************************************************************************/

	for (int j = 0; j < nodes_num; j++)
	{
		score[j] = adj_list[j].size();
		cout << score[j] << "\n";
	}





	system("pause");







	return 0;
}