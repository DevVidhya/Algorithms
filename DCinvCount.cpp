#include<iostream>
using namespace std;

int mer(int a[100],int l,int h,int mid)
{
	int i=l,k=l,temp[100],j=mid,count=0;
	
	while((i<=mid-1)&&(j<=h))
	{
		if(a[i]<=a[j])
		{
			temp[k++]=a[i++];
		}
		else
		{
			temp[k++]=a[j++];
			count+=(mid-i);
		}
	}
	while(i<=mid-1)
	temp[k++]=a[i++];
	while(j<=h)
	temp[k++]=a[j++];
	
	for(i=l;i<=h;i++)
	a[i]=temp[i];
	
	return count;
}

int findinv(int a[100],int l,int h)
{
	int inv=0,mid;

	if(l<h)
	{
		mid=l+(h-l)/2;
		
		inv=findinv(a,l,mid);
		inv+=findinv(a,mid+1,h);
		inv+=mer(a,l,h,mid+1);
	}
	return inv;
}

int main()
{
	int n,i,a[100];
	cout<<"\n Enter number of elements : ";
	cin>>n;
	cout<<"\n Enter elements : ";
	for(i=0;i<n;i++)
	cin>>a[i];
	cout<<findinv(a,0,n-1);
	
	cout<<"\n The resulting array will be sorted :";
	for(i=0;i<n;i++)
	cout<<" "<<a[i];
	return 0;
}
