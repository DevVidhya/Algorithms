#include<iostream>
using namespace std;

int main()
{
	int i;
	cout<<"\n Enter amount : ";
	cin>>i;
	cout<<"\n Rs.2000 : "<<i/2000<<"\n Rs.1000 : "<<(i%2000)/1000<<"\n Rs.500 : "<<((i%2000)%1000)/500<<"\n Rs.100 : "<<(((i%2000)%1000)%500)/100<<"\n Rs.50 : "<<((((i%2000)%1000)%500)%100)/50<<"\n Rs.20 : "<<(((((i%2000)%1000)%500)%100)%50)/20<<"\n Rs.10 : "<<((((((i%2000)%1000)%500)%100)%50)%20)/10;
}
