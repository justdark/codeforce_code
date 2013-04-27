// asd.cpp : Defines the entry point for the console application.
//

#include <iostream>
using namespace std;
#define N 100
#define M 100
void mss(int a[],int len) //maxium subsequence sum
{
	int l[N],r[N];
	int lp[N],rp[N]; //node
	memset(l,0,sizeof(l));memset(r,0,sizeof(r));
	memset(lp,0,sizeof(lp));memset(rp,0,sizeof(rp));
	l[0]=a[0];
	lp[0]=0;
	for (int i=1;i<len;i++)
	{
		if (l[i-1]>=0)
		{
			l[i]=l[i-1]+a[i];
			lp[i]=lp[i-1];
		} else
		{
			l[i]=a[i];
			lp[i]=i;
		}
	}

	r[len-1]=a[len-1];
	rp[len-1]=len-1;
	for (int i=len-2;i>=0;i--)
	{
		if (r[i+1]>=0)
		{
			r[i]=r[i+1]+a[i];
			rp[i]=rp[i+1];
		} else
		{
			r[i]=a[i];
			rp[i]=i;
		}
	}
	int maxs=-10000000000;
	int k=0;
	for (int i=0;i<len;i++)
	{
		if (maxs<l[i]+r[i]-a[i])
		{
			maxs=l[i]+r[i]-a[i];
			k=i;
		}
	}
	cout<<"the max is "<<maxs<<endl;
	cout<<"between "<<lp[k]<<"  "<<rp[k]<<endl;
}
int main()
{
	int n=0;
	int a[100];
	cin>>n;
	for (int i=0;i<n;i++)
		cin>>a[i];
	mss(a,n);
	return 0;
}
