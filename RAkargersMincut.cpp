#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int e,n;

struct edge
{
	int src;
	int dest;
	int wt;
}edges[100];

struct subset
{
	int parent;
	int rank;
}subsets[100];

int findparent(int v)
{
	if(parent[v]==v)
	return v;
	else
	return findparent(parent[v]);
}

void mincut()
{
	int i,count=0,v=n; 
	
	for(i=0;i<n;i++)
	{
		subsets[i].parent=i;
		subsets[i].rank=0;
	}
	
	while(count!=n-1)
	{
		int srcparent=findparent(edges[i].src);
		int destparent=findparent(edges[i].dest);
		
		if(srcparent!=destparent)
		{
			mst[count]=edges[i];
			count++;
			parent[srcparent]=destparent;
		}
		i++;
	}
	
	for(i=0;i<count;i++)
	{
		cout<<"\n"<<mst[i].src<<" "<<mst[i].dest<<" "<<mst[i].wt;
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
	
	mincut();
}
