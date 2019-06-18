#include<iostream>
using namespace std;

int main()
{
	int start[100],dead[100],n,i,j,count=0;
	cout<<"\n Enter number of activities : ";
	cin>>n;
	cout<<"\n Enter starting time of all activities : ";
	for(i=0;i<n;i++)
	cin>>start[i];
	cout<<"\n Enter deadline of all activities : ";
	for(i=0;i<n;i++)
	cin>>dead[i];
	
	i=0;
	count++;
	cout<<"\n The activities are : 0 ";
	for(j=1;j<n;j++)
	{
		if(start[j]>=dead[i])
		{
			cout<<j<<" ";
			i=j;
			count++;
		}
	}
	cout<<"\n Maximum number of jobs : "<<count;
	return 0;
}
