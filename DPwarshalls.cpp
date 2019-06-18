#include<iostream>
using namespace std;

int main()
{
	int graph[10][10],dist[10][10],i,j,n,k;
	
	cout<<"\n Enter number of vertices : ";
	cin>>n;
	cout<<"\n Enter the graph : ";
	for(i=0;i<n;i++)
	for(j=0;j<n;j++)
	cin>>graph[i][j];
	
	for(i=0;i<n;i++)
	for(j=0;j<n;j++)
	dist[i][j]=graph[i][j];
	
	for(k=0;k<n;k++)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(dist[i][j]>dist[i][k]+dist[k][j])
				dist[i][j]=dist[i][k]+dist[k][j];
			}
		}
	}
	
	for(i=0;i<n;i++)
	{
	for(j=0;j<n;j++)
	cout<<dist[i][j]<<" ";
	cout<<"\n";
	}
	
}
