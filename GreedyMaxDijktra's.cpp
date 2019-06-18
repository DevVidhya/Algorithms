#include<iostream>
using namespace std;

int findind(bool mst[10],int key[10],int n)
{
	int min=1000,index;
	for(int i=0;i<n;i++)
	{
		if(mst[i]==false&&key[i]<min)
		{
			min=key[i];
			index=i;
		}
	}
	return index;
}

void findMST(int n,int graph[100][100])
{
	int key[10],i,j,count=0,parent[10];
	bool mst[10];
	for(i=0;i<n;i++)
	mst[i]=false;
	for(i=0;i<n;i++)
	key[i]=1000;
	
	key[0]=0;
	parent[0]=-1;
	
	for(count=0;count<n-1;count++)
	{
		int ind=findind(mst,key,n);
		mst[ind]=true;
		
		for(i=0;i<n;i++)
		{
			if((graph[ind][i])&&(mst[i]==false)&&(key[i]>key[ind]+graph[ind][i]))
			{
				key[i]=graph[ind][i]+key[ind];
				parent[i]=ind;
			}
		}
		
	}
	
	for(i=1;i<n;i++)
	cout<<"\n"<<parent[i]<<"-"<<i<<" "<<(-1)*key[i];
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
	
	for(i=0;i<n;i++)
	for(j=0;j<n;j++)
	graph[i][j]*=-1;
	
	findMST(n,graph);
}
