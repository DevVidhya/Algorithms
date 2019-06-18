#include<iostream>
using namespace std;

int main()
{
	int a[100],n,i,j,max;
	cout<<"\n Enter length of array : ";
	cin>>n;
	cout<<"\n Enter elements : ";
	for(i=0;i<n;i++)
	cin>>a[i];
	
	int dp[100];
	dp[0]=1;
	cout<<"\n 1 ";
	for(i=1;i<n;i++)
	{
		dp[i]=1;
		for(j=0;j<i;j++)
		{
			if(a[i]>a[j]&&dp[i]<dp[j]+1)
			dp[i]=dp[j]+1;
		}
		cout<<dp[i]<<" ";
	}
	
	max=dp[0];
	for(i=1;i<n;i++)
	{
		if(max<dp[i])
		max=dp[i];
	}
	
	cout<<"\n Longest increasing subsequence is of length : ";
	cout<<max;
}
