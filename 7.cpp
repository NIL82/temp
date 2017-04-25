#include<iostream>
#include<stdlib.h>;
#define INF 999
#define MAX 10
using namespace std;

class Graph
{
	string names[MAX];
	int nodes, edges,cost[MAX][MAX];

public:
	Graph()
	{
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
	void accept();
	void display();
	void kruskal();
	int position(string);
};
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
void Graph::kruskal()
{
	int mincost = 0;
	int n = nodes;
	edges = 1;
	int min, i, j, u, v, a, b;
	while(edges<n)
	{
		min=999;

		for(i=0;i<n;i++)
		{
			for(j=i;j<n;j++)
			{
				if(cost[i][j]<min)
				{
					min=cost[i][j];
					a=u=i;
					b=v=j;
				}
			}
		}

		if(u!=v)
		{
			edges++;
			cout<<"\nDistance between city : "<<names[a]<<"->"<<names[b]<<" = " <<min<<" kms";
			mincost=mincost+min;
		}
		cost[a][b]=cost[b][a]=999;
	}
	cout<<"\nMinimum cost : "<<mincost;
}


int main()
{
	Graph g;
	int cost;

	g.accept();
	g.display();
	g.kruskal();
	return 0;
}

