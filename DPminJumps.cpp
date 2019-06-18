#include<iostream>
using namespace std;

int main()
{
	int jumps[100],i,j,n;
	cout<<"\n Enter total number of boxes : ";
	cin>>n;
	cout<<"\n Enter maximum number of jumps from each box : ";
	for(i=0;i<n;i++)
	cin>>jumps[i];
	
	if(n==0)
	{
		cout<<"Can't reach end ";
		return 0;
	}
	
	if(jumps[0]==0)
	{
		cout<<"Can't reach end ";
		return 0;
	}
	
	int dp[n];
	for(i=0;i<n;i++)
	dp[i]=INT_MAX;
	dp[0]=0;
	for(i=1;i<n;i++)
	{
		for(j=0;j<i;j++)
		{
			if(j+jumps[j]>=i&&dp[j]!=INT_MAX)
			{
				dp[i]=dp[j]+1;
				break;
			}
		}
	}
	
	cout<<dp[n-1];
	return 0;
}
