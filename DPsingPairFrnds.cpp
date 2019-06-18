#include<iostream>
using namespace std;

int main()
{
	int i,n;
	cout<<"\n Enter number of elements : ";
	cin>>n;
	int dp[n+1];
	dp[0]=0;
	dp[1]=1;
	dp[2]=2;
	for(i=3;i<=n;i++)
	dp[i]=dp[i-1]+(i-1)*dp[i-2];
	
	cout<<"\n "<<dp[n];
	return 0;
}
