#include<iostream>
#include<stdlib.h>;
#define INF 999
#define MAX 10
using namespace std;

class Graph
{
	string names[MAX];
	int nodes, edges,cost[MAX][MAX], distance[MAX], from[MAX], visited[MAX],source;

public:
	Graph()
	{
		edges = 1;
		source=0;
		nodes=0;
		for(int i=0; i<MAX; i++)
		{
			for(int j=0; j<MAX; j++)
			{
				if(i==j)
				    cost[i][j] = 0;
				else
					cost[i][j] = INF;
			}
		}
	}
	void initialize();
	void accept();
	void display();
	void dijkstra();
	int position(string);
};
void Graph::initialize()
{
	int i;
	for(i=0; i<nodes; i++)
	{
		from[i] = source;
		visited[i] = 0;
		distance[i] = cost[source][i];
	}
	visited[source] = 1;
	distance[source] = 0;
}
void Graph::accept()
{
	int i, j,k, wt;
	string start, end;
	cout<<"\nEnter no. of vertex : ";
	cin>>nodes;
	cout<<"\nEnter names of vertex: ";
	for(int i=0; i<nodes; i++)
	{
		cin>>names[i];
	}
	cout<<"\nEnter no. of edges: ";
	cin>>edges;
	for(i=0; i<edges; i++)
	{
		cout<<"\nEnter source destination and weight: ";
		cin>>start>>end;
		cout<<"\nEnter weight: ";
		cin>>wt;

		j = position(start);
		k = position(end);

		cost[j][k] = wt;
		cost[k][j] = wt;
	}
}
int Graph::position(string s)
{
	int i=0;
	for(i=0; i<nodes; i++)
		if(names[i] == s)
			return i;

	cout<<"!Vertex not found!";
}
void Graph::display()
{
	int i, j;
	for(i=0; i<nodes; i++)
		cout<<"\t"<<names[i];
	for(i=0; i<nodes; i++)
	{
		cout<<"\n"<<names[i];
		for(j=0; j<nodes; j++)
				cout<<"\t"<<cost[i][j];
	}
}
void Graph::dijkstra()
{
	string s;
	int mindistance, mincost=0, u, v, i,j;
	cout<<"\nEnter source vertex for Dijkstra: ";
	cin>>s;
	source = position(s);
	while(source<0 || source>nodes-1)
	{
		cout<<"\nWrong vertex, renter source vertex for dijkstra: ";
		cin>>s;
		source = position(s);
	}
	initialize();
	edges=1;
	while(edges<nodes-1)
	{
		mindistance = INF;

		for(i=0; i<nodes; i++)
		{
			while(visited[i] == 0 && distance[i]<mindistance)
			{
				mindistance = distance[i];
				v = i;
			}
		}
		visited[v] = 1;

		for(i=0; i<nodes; i++)
		{
			if(visited[i] == 0 && distance[i]>(cost[i][v]+mindistance))
			{
				distance[i] = cost[i][v]+mindistance;
				from[i] = v;
			}
		}
		edges++;
	}
	for(i=0;i<nodes;i++)
	{
		if(i!=source)
		{
			cout<<"\n\nDistance of vertex "<<names[i]<<"="<<distance[i];
			cout<<"\nPath ="<<names[i];
			j=i;
			do
			{
				j=from[j];
				cout<<"<-"<<names[j];

			}while(j!=source);
		}
	}
}

int main()
{
	Graph g;
	int cost;

	g.accept();
	g.display();
	g.dijkstra();
	return 0;
}

