#include<iostream>
#include<cstdlib>
#include<time.h>
using namespace std;

int n;

void swap(int* a,int* b)
{
	int t=*a;
	*a=*b;
	*b=t;
}

int partition(int A[100],int l,int h)
{
	int i=l-1,j,pivot=A[h];
	
	for(j=l;j<h;j++)
	{
		if(A[j]<=pivot)
		{
			i++;
			swap(&A[j],&A[i]);
		}
	}
	swap(&A[i+1],&A[h]);
	return (i+1);
}

int genrand(int A[100],int l,int h)
{
	int k;
	srand(time(NULL));
	k=rand()%(h-l);
	swap(&A[h],&A[l+k]);
	return partition(A,l,h);
}

void quicksort(int A[100],int l,int h)
{
	if(l<h)
	{
		int pi=genrand(A,l,h);
		
		quicksort(A,l,pi-1);
		quicksort(A,pi+1,h);
	}
}

int main()
{
	int A[100],i;
	cout<<"\n Enter number of elements : ";
	scanf("%d",&n);
	cout<<"\n Enter the elements : ";
	for(i=0;i<n;i++)
	cin>>A[i];
	
	quicksort(A,0,n-1);
	cout<<"\n The sorted order is : ";
	for(i=0;i<n;i++)
	cout<<" "<<A[i];
	return 0;
}
