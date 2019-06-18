#include<bits/stdc++.h>
using namespace std;

int n;

int shortPath(int graph[100][100])
{
	int dist[n],path[n];
	
	dist[n-1]=0;
	
	for(int i=n-2;i>=0;i--)
	{
		dist[i]=1000;
		for(int j=i;j<n;j++)
		{
			dist[i]=min(dist[i],graph[i][j]+dist[j]);
			if(dist[i]==graph[i][j]+dist[j])
			path[i]=j;
		}
	}
	
	cout<<"\n Path : 0";
	for(int i=0;i!=n-1;)
	{
		cout<<"-"<<path[i];
		i=path[i];
	}
	cout<<"\n Shortest distance : ";
	return dist[0];
}

int main()
{
	cout<<"\n Enter number of vertices in the graph : ";
	cin>>n;
	int graph[100][100];
	cout<<"\n Enter distace between nodes ( 1000 if no edge ) : ";
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	cin>>graph[i][j];
	
	cout<<shortPath(graph);
}
