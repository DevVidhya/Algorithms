#include<iostream>
#include<algorithm>
using namespace std;

struct job
{
	char id;
	int dead;
	int profit;
};

bool comparision(job a,job b)
{
	return a.profit>b.profit;
}

void schedule(int n, job jobs[100])
{
	sort(jobs,jobs+n,comparision);
	
	int result[100];
	bool slot[100];
	
	for(int i=0;i<n;i++)
	slot[i]=false;
	
	for(int i=0;i<n;i++)
	{
		for(int j=min(n,jobs[i].dead)-1;j>=0;j--)
		{
			if(slot[j]==false)
			{
				result[j]=i;
				slot[j]=true;
				break;
			}
		}
	}
	
	cout<<"\n";
	for(int i=0;i<n;i++)
	{
		if(slot[i])
		{
			cout<<jobs[result[i]].id<<" ";
		}
	}
}

int main()
{
	int n,i;
	job j[100];
	cout<<"\n Enter number of jobs : ";
	cin>>n;
	cout<<" Enter job id, deadline and profit for the jobs : \n";
	for(i=0;i<n;i++)
	{
		cin>>j[i].id;
		cin>>j[i].dead;
		cin>>j[i].profit;
	}
	
	schedule(n,j);
}
