#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int e,n,dist[100];

struct edge
{
	int src;
	int dest;
	int wt;
}edges[100];

void ford()
{
	int i,j;
	
	for(i=0;i<n;i++)
	dist[i]=1000;
	dist[0]=0;
	
	for(i=1;i<=n-1;i++)
	{
		for(j=0;j<e;j++)
		{
			if(dist[edges[j].src]!=1000&&dist[edges[j].src]+edges[j].wt<dist[edges[j].dest])
			dist[edges[j].dest]=dist[edges[j].src]+edges[j].wt;
		}
	}
	
	for(j=0;j<e;j++)
	{
		if(dist[edges[j].src]!=1000&&dist[edges[j].src]+edges[i].wt<dist[edges[j].dest])
		cout<<"\n Negative edge cycle is present ";
	}
	
	for(i=0;i<n;i++)
	{
		cout<<"\n"<<i<<"  -  "<<dist[i];
	}
}

int main()
{
	cout<<"\n Enter number of vertices : ";
	cin>>n;
	cout<<"\n Enter number of edges : ";
	cin>>e;
	cout<<"\n Enter the source, destination, and weight of edges ";
	for(int i=0;i<e;i++)
	{
		cin>>edges[i].src;
		cin>>edges[i].dest;
		cin>>edges[i].wt;
	}
	
	ford();
}
