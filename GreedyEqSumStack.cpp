#include<iostream>
using namespace std;

int main()
{
	int i,a[100],b[100],c[100],l,m,n,sum1=0,sum2=0,sum3=0;
	cout<<"\n Enter sizes if 3 stacks : ";
	cin>>l>>m>>n;
	cout<<"\n Enter elements of stack 1 : ";
	for(i=0;i<l;i++)
	cin>>a[i];
	cout<<"\n Enter elements of stack 2 : ";
	for(i=0;i<m;i++)
	cin>>b[i];
	cout<<"\n Enter elements of stack 3 : ";
	for(i=0;i<n;i++)
	cin>>c[i];
	for(i=0;i<l;i++)
	sum1+=a[i];
	for(i=0;i<m;i++)
	sum2+=b[i];
	for(i=0;i<n;i++)
	sum3+=c[i];
	
	while(!((sum1==sum2)&&(sum2==sum3)))
	{
		if(l==0||m==0||n==0)
		{
			cout<<"\n Sum = 0 ";
			return 0;
		}
		if(sum1>sum2&&sum1>sum3)
		{
			sum1=sum1-a[--l];
		}
		else if(sum2>sum1&&sum2>sum3)
		{
			sum2=sum2-b[--m];
		}
		else if(sum3>sum1&&sum3>sum2)
		{
			sum3=sum3-c[--n];
		}
	}
	
	cout<<"\n Sum = "<<sum1;
}
