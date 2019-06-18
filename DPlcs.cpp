#include<iostream>
#include<string>
using namespace std;

int max(int a,int b)
{
	return (a>b)?a:b;
}

int findlength(string X,string Y,int n,int m)
{
	if(n==0||m==0)
	return 0;
	if(X[n-1]==Y[m-1])
	return 1+findlength(X,Y,n-1,m-1);
	else
	return max(findlength(X,Y,n-1,m),findlength(X,Y,n,m-1));
}

int main()
{
	string X,Y;
	int n,m;
	cout<<"\n Enter 2 strings : ";
	cin>>X;
	cin>>Y;
	n=X.length();
	m=Y.length();
	cout<<findlength(X,Y,n,m);
}
