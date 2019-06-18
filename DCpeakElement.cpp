#include<iostream>
using namespace std;

int findmax(int a[100][100],int n,int mid,int &max)
{
	int index;
	max=a[0][mid];
	for(int i=0;i<n;i++)
	{
		if(a[i][mid]>max)
		{
			index=i;
			max=a[i][mid];
		}
	}
	return index;
}

int findpeak(int a[100][100],int n,int m,int mid)
{
	int u,max;
	
	u=findmax(a,n,mid,max);
	
	if(mid==(m-1)||mid==0)
	return max;
	
	if((a[u][mid-1]<=max)&&(a[u][mid+1]<=max))
	return max;
	
	if(a[u][mid-1]>max)
	return findpeak(a,n,m,mid-mid/2);
	
	if(a[u][mid+1]>max)
	return findpeak(a,n,m,mid+mid/2);
}

int main()
{
	int a[100][100],n,m,i,j;
	cout<<"\n Enter number of rows and columns : ";
	cin>>n;
	cin>>m;
	cout<<"\n Enter the matrix : \n ";
	for(i=0;i<n;i++)
	for(j=0;j<m;j++)
	cin>>a[i][j];
	cout<<findpeak(a,n,m,m/2);
}
