#include<iostream>
using namespace std;

int isprime(int k)
{
	if(k<=1)
	return 0;
	
	if(k<=3)
	return 1;
	
	if((k%2==0)||(k%3==0))
	return 0;
	
	for(int i=5;i*i<k;i=i+6)
	if((k%i==0)||(k%(i+2)==0))
	return 0;
	
	return 1;
}

void printprime(int n)
{
	int i;
	for(i=1;i<=n;i++)
	{
		if(isprime(i))
		cout<<i<<" ";
	}
}

int main()
{
	int n;
	cout<<"\n Enter a number : ";
	cin>>n;
	printprime(n);
}
