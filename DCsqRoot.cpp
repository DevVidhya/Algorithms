#include<iostream>
using namespace std;

int findroot(int n)
{
	if(n==0||n==1)
	return n;
	
	int start=1,end=n,ans;
	
	while(start<end)
	{
		int mid=start+(end-start)/2;
		
		if(mid*mid==n)
		return mid;
		
		if(mid*mid<n)
		{
			ans=mid;
			start=mid+1;
		}
		else
		end=mid-1;
	}
	return ans;
}

int main()
{
	int n;
	cout<<"\n Enter the number : ";
	cin>>n;
	cout<<findroot(n);
	return 0;
}
