#include<iostream>
using namespace std;

int maximum(int a,int b,int c)
{
	if((a>b)&&(a>c))
	return a;
	else if((b>a)&&(b>c))
	return b;
	else if((c>a)&&(c>b))
	return c;
}

int mer(int a[100],int l,int h,int mid)
{
	int i,max=0,leftmax=INT_MIN,rightmax=INT_MIN;
	for(i=mid;i>=l;i--)
	{
		max=max+a[i];
		if(max>leftmax)
		leftmax=max;
	}
	max=0;
	for(i=mid+1;i<=h;i++)
	{
		max=max+a[i];
		if(max>rightmax)
		rightmax=max;
	}

    return leftmax+rightmax;
}

int findmax(int a[100],int l,int h)
{
	if(l==h)
		return a[l];
	
	int mid=l+(h-l)/2;
	
	return maximum(findmax(a,l,mid),findmax(a,mid+1,h),mer(a,l,h,mid));
}

int main()
{
	int i,a[100],n;
	cout<<"\n Enter number of elements : ";
	cin>>n;
	cout<<"\n Enter elements : ";
	for(i=0;i<n;i++)
	cin>>a[i];
	cout<<findmax(a,0,n-1);
	return 0;
}
