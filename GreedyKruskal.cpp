#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int e,n,parent[100];

struct edge
{
	int src;
	int dest;
	int wt;
}edges[100],mst[100];

bool compare(edge e1,edge e2)
{
	return e1.wt<e2.wt;
}

int findparent(int v)
{
	if(parent[v]==v)
	return v;
	else
	return findparent(parent[v]);
}

void kruskal()
{
	int i,count=0; 
	sort(edges,edges+e,compare);
	
	for(i=0;i<n;i++)
	{
		parent[i]=i;
	}
	
	i=0;
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
	
	kruskal();
}
