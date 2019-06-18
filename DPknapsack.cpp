#include<iostream>
using namespace std;

int max(int a,int b)
{
	return (a>b)?a:b;
}

int main()
{
	int i,values[100],wt[100],n,W;
	cout<<"\n Enter number of items : ";
	cin>>n;
	cout<<"\n Enter value of items : ";
	for(i=0;i<n;i++)
	cin>>values[i];
	cout<<"\n Enter weights of items : ";
	for(i=0;i<n;i++)
	cin>>wt[i];
	cout<<"\n Enter total weight possible : ";
	cin>>W;
	
	int k[n+1][W+1],w;
	for(i=0;i<=n;i++)
	{
		for(w=0;w<=W;w++)
		{
			if(i==0||w==0)
			k[i][w]=0;
			else if(wt[i-1]<=w)
		    k[i][w] = max(values[i-1] + k[i-1][w-wt[i-1]],  k[i-1][w]); 
            else
            k[i][w] = k[i-1][w]; 
		}
	}
	
	cout<<"\n"<<k[n][W];
}
