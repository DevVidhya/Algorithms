#include<iostream>
#include<time.h>
using namespace std;

int getnum()
{
	time_t t=time(NULL);
	
	struct tm* tm=localtime(&t);
	
	long long int x;
	x=(tm->tm_hour*1000000000)+(tm->tm_min*10000000)+(tm->tm_sec*100000)+(tm->tm_mday*1000)+(tm->tm_year*10);
	return x;
}

int getkey()
{
	long long int k=getnum();
	
	k=k*k;
	k=k/1000;
	
	return k%100000000;
}

int main()
{
	cout<<getkey()<<"\n";



	cout<<getkey()<<"\n";
}
