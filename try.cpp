#include<iostream>
using namespace std;

void lcis(int arr1[10],int arr2[10],int n,int m)
{
	int parent[10],i,j,current,last,table[10];
	for(j=0;j<m;j++)
	table[j]=0;
	
	for(i=0;i<n;i++)
	{
		current=0;
		last=-1;
		for(j=0;j<m;j++)
		{
			if(arr1[i]==arr2[j])
			{
				if(current+1>table[j])
		    	{
			    	table[j]=current+1;	
			    	parent[j]=last;
		    	}
			}
			
			if(arr1[i]>arr2[j])
			{
				if(table[j]>current)
				{
					current=table[j];
					last=j;
				}
			}
			
		}
	}
	
	int max=table[0],index;
	for(j=0;j<m;j++)
	{
		if(max<table[j])
		{
			max=table[j];
			index=j;
		}
	}
	cout<<"\n "<<max;

    i=0;
    int result[10];
    while(index!=-1)
	{
        result[i++]=arr2[index];
		index=parent[index];		
	}	
	
	cout<<"\n";
	for(j=i-1;j>=0;j--)
	cout<<result[j]<<" ";
}

int main()
{
	int i,n,m,arr1[10],arr2[10];
	cout<<"\n Enter number of elements in 2 arrays : ";
	cin>>n;
	cin>>m;
	cout<<"\n Enter array 1 elements : ";
	for(i=0;i<n;i++)
	cin>>arr1[i];
	cout<<"\n Enter array 2 elements : ";
	for(i=0;i<m;i++)
	cin>>arr2[i];
	
	lcis(arr1,arr2,n,m);
}
