#include<iostream>
using namespace std;

int main()
{
	int a[100],n,W,i,w;
	cout<<"\n Enter number of elements : ";
	cin>>n;
	cout<<"\n Enter elements : ";
	for(i=0;i<n;i++)
	cin>>a[i];
	cout<<"\n Enter total weight : ";
	cin>>W;
	
	int dp[n+1][W+1];
	
	for(i=0;i<=n;i++)
	{
		for(w=0;w<=W;w++)
		{
			if(w==0||i==0)
			dp[i][w]=0;
			else if(a[i-1]<=w)
			dp[i][w]=dp[i-1][w]||dp[i-1][w-a[i-1]];
			else
			dp[i][w]=dp[i-1][w];
		}
	}
	
	if(dp[n][W]==1)
	cout<<"\n Possible ";
	else
	cout<<"\n Not Possible ";
}
