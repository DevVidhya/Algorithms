#include<iostream>
using namespace std;

int findMin(int n,int key[100],bool mst[100])
{
	int min=INT_MAX,index;
	for(int i=0;i<n;i++)
	{
		if(mst[i]==false&&min>key[i])
		{
			min=key[i];
			index=i;
		}
	}
	return index;
}

void findMST(int n,int graph[100][100])
{
	int i,parent[100],key[100],ind;
	bool mst[100];
	
	for(i=0;i<n;i++)
	{
		key[i]=INT_MAX;
		mst[i]=false;
	}
	
	key[0]=0;
	parent[0]=-1;
	
	for(int count=0;count<n-1;count++)
	{
		ind=findMin(n,key,mst);
		mst[ind]=true;
		
		for(i=0;i<n;i++)
		{
			if(graph[ind][i]&&mst[i]==false&&(graph[ind][i]+key[ind])<key[i])
			{
				key[i]=graph[ind][i]+key[ind];
				parent[i]=ind;
			}
		}
	}
	
	cout<<"\n";
	for(i=1;i<n;i++)
	cout<<parent[i]<<"-"<<i<<"  "<<key[i]<<"\n";
}

int main()
{
	int i,j,n,graph[100][100];
	cout<<"\n Enter number of vertices : ";
	cin>>n;
	cout<<"\n Enter adjacency matrix of the graph :\n";
	for(i=0;i<n;i++)
	for(j=0;j<n;j++)
	cin>>graph[i][j];
	
	findMST(n,graph);
}
