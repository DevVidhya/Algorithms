#include<iostream>
#include<string>
using namespace std;

string common(string str1,string str2)
{
	string result;
	int i,j,a,b;
	a=str1.length();
	b=str2.length();
	for(i=0,j=0;i<a&&j<b;i++,j++)
	{
		if(str1[i]!=str2[j])
		break;
		result.push_back(str1[i]);
	}
	return result;
}

string findpre(string str[100],int l,int h)
{
	if(l==h)
	return str[l];
	
	if(l<h)
	{
		int mid=l+(h-l)/2;
		string str1=findpre(str,l,mid);
		string str2=findpre(str,mid+1,h);
		return common(str1,str2);
	}
}

int main()
{
	string str[100];
	int i,n;
	cout<<"\n Enter number of strings : ";
	cin>>n;
	cout<<"\n Enter elments : ";
	for(i=0;i<n;i++)
	cin>>str[i];
	cout<<findpre(str,0,n-1);
}
