#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <cstring>
#include <string.h>
#include <math.h>
using namespace std;
int n,m;
int main()
{	
	cin>>n>>m;
	int p=0;
	vector<int> a,b;
	int at[50];
	for (int i=0;i<50;i++)
		at[i]=-1;
	vector<int> team[40];
	for (int i=1;i<=n;i++)
		a.push_back(i);
	int x[2500],y[2500];
	for (int i=0;i<m;i++)
	{
		cin>>x[i]>>y[i];

		if (at[x[i]]!=-1 && at[y[i]]==-1)
		{
			at[y[i]]=at[x[i]];
			team[at[y[i]]].push_back(y[i]);
		} else if (at[y[i]]!=-1 && at[x[i]]==-1)
		{
			at[x[i]]=at[y[i]];
			team[at[y[i]]].push_back(x[i]);
		} else if(at[x[i]]==-1 && at[y[i]]==-1)
		{
			at[x[i]]=p;
			at[y[i]]=p;
			p++;
			team[at[x[i]]].push_back(x[i]);
			team[at[x[i]]].push_back(y[i]);
		} else if (at[x[i]]!=at[y[i]] && at[x[i]]!=-1 && at[x[i]]!=-1)
		{
			cout<<-1<<endl;
			return 0;
		}
	}

	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<n/3;j++)
		{
			if (at[i]==-1 && team[j].size()<3)
			{
				at[i]=j;
				team[j].push_back(i);
				break;
			}
		}
	}
	for (int i=0;i<n/3;i++)
	{
		if (team[i].size()!=3)
		{
			cout<<-1<<endl;
			return 0;
		}
	}
	for (int i=1;i<=n;i++)
	{
		if (at[i]==-1)
		{
			cout<<-1<<endl;
			return 0;
		}
	}

	for (int i=0;i<n/3;i++)
	{
		cout<<team[i][0]<<" "<<team[i][1]<<" "<<team[i][2]<<endl;
	}
	return 0;
}