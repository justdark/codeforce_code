
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <cstring>
#include <string.h>
#include <math.h>
using namespace std;

int n,m,k;
int a[100001];
int b[100001];
void qsort(int a[],int lx,int rx)
{
   int i,j,t,x;
   i=lx; j=rx;
   x=a[rand()%(j-i+1)+i];
   do{
	   while (a[i]<x) i+=1;
	   while (a[j]>x) j-=1;
	   if (i<=j)
	   {
		   t=a[i];a[i]=a[j];a[j]=t;
		   i+=1;j-=1;
	   }
   }
   while (i<=j);
   if (lx<j) qsort(a,lx,j);
   if (i<rx) qsort(a,i,rx);
}

int main()
{	
	cin>>n>>m>>k;
	for (int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	qsort(a,0,n-1);
	for (int i=0;i<m;i++)
	{
		cin>>b[i];
	}
	qsort(b,0,m-1);
	int pa=0;
	int pb=0;
	while (true)
	{
		while (a[pa]<b[pb] && pa<n)
			pa++;
		while (a[pa]>b[pb] && pb<m)
			pb++;
		if (a[pa]!=b[pb])
			break;
		a[pa]=-1;
		b[pb]=-1;
		pa++;
		pb++;
	}
	qsort(a,0,n-1);
	qsort(b,0,m-1);
	pa=0;
	pb=0;
	while (a[pa]==-1 && pa<n)
		pa++;
	while (b[pb]==-1 && pb<m)
		pb++;
	while (true)
	{
		while (a[pa]>b[pb] && pb<m)
			pb++;
		if (a[pa]>b[pb])
		{
			cout<<"YES"<<endl;
			break;
		}
		pa++;
		pb++;
		if (pa>n)
		{
			cout<<"NO"<<endl;
			break;
		}
	}
	return 0;
}